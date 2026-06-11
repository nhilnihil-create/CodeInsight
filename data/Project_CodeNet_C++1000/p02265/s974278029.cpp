#include <iostream>
#include <cstdio>
using namespace std;

typedef struct Node{
  int key;
  Node *prev, *next;
} Node;

Node *nil;

void insert_cell(int key)
{
  Node *x;
  x = new Node;
  x->key = key;
  x->prev = nil;
  x->next = nil->next;
  x->next->prev = x;
  nil->next = x;
}

void deleteNode(Node *t)
{
  if(t != nil){
    t->prev->next = t->next;
    t->next->prev = t->prev;
    t->prev = NULL;
    t->next = NULL;
    delete t;
  }
}

void delete_cell(int x)
{
  Node *cell;
  cell = new Node;
  cell = nil->next;
  while(cell->key != x && cell != nil)
    cell = cell->next;
  deleteNode(cell);
}

void deleteFirst()
{
  deleteNode(nil->next);
}

void deleteLast()
{
  deleteNode(nil->prev);
}
  

int main()
{
  nil = new Node;
  nil->prev = nil;
  nil->next = nil;
  int n, k;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    char s[20], c;
    scanf("%s%d", s, &k);
    if(s[0] == 'i'){
      insert_cell(k);
    }else{
      if(s[6] == 'F')
	deleteFirst();
      else if(s[6] == 'L')
	deleteLast();
      else
	delete_cell(k);
    }
  }
  Node *p;
  p = new Node;
  p = nil->next;
  for(int i = 0; p != nil; i++, p = p->next)
    if(i)
      cout << " " << p->key;
    else
      cout << p->key;  
  delete p;
  cout << endl;
}