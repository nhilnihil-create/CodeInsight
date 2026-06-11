#include<cstdio>
#include<cstdlib>
#include<cstring>

struct Node{
	int key;
	Node *next, *prev;
};

Node *nil;

Node* listsearch(int key) {
	Node *cur = nil->next;
	while (cur != nil && cur->key != key) {
		cur = cur->next;
	}
	return cur;
}

void init() {
	nil = (Node *)malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}

void printlist() {
	Node *cur = nil->next;
	int isf = 0;
	while (1) {
		if (cur == nil) {
			break;
		}
		if (isf++ > 0) {
			printf(" ");
		}
		printf("%d", cur->key);
		cur = cur->next;
	}
	printf("\n");
}

void deletenode(Node *t){
	if (t == nil) {
		return;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
}

void deletefirst(){
	deletenode(nil->next);
}

void deletelast() {
	deletenode(nil->prev);
}

void deletekey(int key){
	deletenode(listsearch(key));
}

void insert(int key) {
	Node *x = (Node *)malloc(sizeof(Node));
	x->key = key;
	x->next = nil->next;
	nil->next->prev = x;
	nil->next = x;
	x->prev = nil;
}

int main()
{
	int key, n, i;
	char s[20];
	scanf("%d", &n);
	init();
	for (i = 0; i < n; i++) {
		scanf("%s%d", s, &key);
		if (s[0] == 'i') {
			insert(key);
		}
		else if (s[0] == 'd') {
			if (strlen(s) > 6) {
				if (s[6] == 'F') {
					deletefirst();
				}
				else if (s[6] == 'L') {
					deletelast();
				}
			}
			else deletekey(key);
		}
	}
	printlist();
    return 0;
}