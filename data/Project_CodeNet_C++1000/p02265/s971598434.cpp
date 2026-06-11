#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
typedef long long ll;
using namespace std;

struct node {
	int key;
	node *next, *prev;
};

node *nil;

void init() {
	nil = (node*)malloc(sizeof(node));
	nil->next = nil;
	nil->prev = nil;
}

void deleteNode(node *t) {
	if (t == nil) return;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
}

void deleteFirst() {
	deleteNode(nil->next);
}

void deleteLast() {
	deleteNode(nil->prev);
}

node* searchList(int x) {
	for (node* temp = nil->next; temp != nil; temp = temp->next) {
		if (temp->key == x) {
			return temp;
		}
	}
}

void deleteKey(int key) {
	node* t = searchList(key);
	deleteNode(t);
}

void insert(int key) {
	node *t = (node*)malloc(sizeof( node));
	t->key = key;
	t->next = nil->next;
	t->prev = nil;
	nil->next->prev = t;
	nil->next = t;
}

void printList() {
	node *t = nil->next;
	int i = 0;
	while (t != nil) {
		if (i < 1) {
			i++;
			cout << t->key;
			t = t->next;
			continue;
		}
		
		cout << ' ' << t->key;
		t = t->next;
	}
}

int main() {
	//freopen("run.in", "r", stdin);
	//freopen("run.out", "w", stdout);

	init();
	string cmd;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> x;
			insert(x);
		}
		else if (cmd == "delete") {
			cin >> x;
			deleteKey(x);
		}
		else if (cmd == "deleteFirst") {
			deleteFirst();
		}
		else if (cmd == "deleteLast") {
			deleteLast();
		}
	}

	printList();
	cout << endl;


	return 0;
}