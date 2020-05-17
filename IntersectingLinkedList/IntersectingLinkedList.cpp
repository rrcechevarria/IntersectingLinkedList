#include "IntersectingLinkedList.h"
#include "stdio.h"


using namespace std;

void display(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int countNode(Node* head) {
	int ctr = 0;
	while (head != NULL) {
		ctr++;
		head = head->next;
	}
	return ctr;
}

int connectingNode(Node *list1, Node *list2) {
	int list1Len = countNode(list1);
	int list2Len = countNode(list2);
	int nNode;
	Node* head1, * head2;
	if (list1Len > list2Len) {
		nNode = list1Len - list2Len;
		head1 = list1;
		head2 = list2;
	}
	else {
		nNode = list2Len - list1Len;
		head1 = list2;
		head2 = list1;
	}
	for (int i = 0; i < nNode; i++) {
		head1 = head1->next;
	}

	while (head1 != NULL) {
		if (head1->data == head2->data) {
			return head1->data;
		}
		else {
			head1 = head1->next;
			head2 = head2->next;
		}
	}

	return 0;

}

int main() {
	Node* node1 = new Node;
	Node *list1, * list2;
	list1 = node1;
	node1->data = 10;
	node1->next = new Node;
	Node * node2 = node1->next;
	node2->data = 20;
	node2->next = new Node;
	Node* node22 = node2->next;
	node22->data = 22;
	node22->next = new Node;
	Node * node3 = node22->next;
	node3->data = 30;
	node3->next = new Node;
	Node * node4 = node3->next;
	node4->data = 40;
	node4->next = new Node;
	Node* node5 = node4->next;
	node5->data = 50;
	node5->next = NULL;

	Node* node1_1 = new Node;
	list2 = node1_1;
	node1_1->data = 100;
	node1_1->next = new Node;
	Node* node2_1 = node1_1->next;
	node2_1->data = 200;
	node2_1->next = new Node;
	Node* node3_1 = node2_1->next;
	node3_1->data = 300;
	node3_1->next = node4;

	display(list1);
	display(list2);

	int intersect = connectingNode(list1, list2);

	if (intersect != 0) {
		cout << "\nIntersection is at " << intersect;
	}
	else {
		cout << "\nNo intersection";
	}

	_getch();
	return 0;
}