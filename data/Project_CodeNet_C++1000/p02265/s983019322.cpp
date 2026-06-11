#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_OP_NUM 2000000
#define MAX_KEY_VALUE 1000000000
#define MAX_LIST_LENGTH 1000000

using namespace std;

struct Cell {
  int value;
  Cell* next;
  Cell* prev;
};

class LinkedList {
public:
  LinkedList() {
    nil = new Cell();
    nil->next = nil;
    nil->prev = nil;

    head = nil;
    last = nil;
  }

  void insert(int value) {
    Cell* cell = new Cell();
    cell->value = value;

    cell->prev = head;
    cell->next = head->next;
    head->next->prev = cell;
    head->next = cell;
  }

  void remove(int value) {
    Cell* cell = findCell(value);
    if(cell == NULL) return;
    deleteCell(cell);
  }

  void deleteFirst() {
    Cell* cell = head->next;
    if(cell == nil) return;

    deleteCell(cell);
  }

  void deleteLast() {
    Cell* cell = last->prev;
    if(cell == nil) return;

    deleteCell(cell);
  }

  void print() {
    Cell* cell = head->next;
    while(cell != nil) {
      printf("%d", cell->value);
      cell = cell->next;

      if(cell != nil) {
        printf(" ");
      }
    }
  }
private:
  void deleteCell(Cell* cell) {
    cell->prev->next = cell->next;
    cell->next->prev = cell->prev;
    delete cell;
  }

  Cell* findCell(int value) {
    Cell* cell = head->next;

    while(cell != nil) {
      if(cell->value == value) {
        return cell;
      }
      cell = cell->next;
    }
    return NULL;
  }

  Cell* nil;
  Cell* head;
  Cell* last;
};

int main() {
  int n;
  scanf("%d", &n);

  LinkedList list;

  char operation[255];
  int arg;
  for(int i=0; i<n; i++) {
    scanf("%s%d\n", operation, &arg);
    //printf("%s %d\n", operation, arg);

    if(strcmp("insert", operation) == 0) {
      list.insert(arg);
    } else if(strcmp("delete", operation) == 0) {
      list.remove(arg);
    } else if(strcmp("deleteFirst", operation) == 0) {
      list.deleteFirst();
    } else if(strcmp("deleteLast", operation) == 0) {
      list.deleteLast();
    } else {
      printf("unknown op %s\n", operation);
      return 1;
    }

    //list.print();
    //printf("\n");
  }


  list.print();
  printf("\n");
  return 0;
}