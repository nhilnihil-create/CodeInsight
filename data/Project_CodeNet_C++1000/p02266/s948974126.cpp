#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 20000
 
typedef struct {
  int data[MAX+2];
  int head, tail;
} Stack;
 
void init(Stack *st) {
  st->head = st->tail = 0;
}
 
void push(Stack *st, int x) {
  if(st->tail == MAX+2) return;
  st->data[(st->tail)++] = x;
}
 
int pop(Stack *st) {
  return st->data[--(st->tail)];
}
 
int empty(Stack *st) {
  return st->head == st->tail;
}
 
int size(Stack *st) {
  return st->tail - st->head;
}
 
int main() {
  char buf[MAX+2];
  int len, ans = 0;  
  Stack st1, st2, st3, st4;
  int cnt = 0;
  int i, j;
   
  scanf("%s", buf);
  len = strlen(buf);
 
  init(&st1);
  init(&st2);
  init(&st3);
  init(&st4);
   
  for(i = 0; i < len; i++) {
    if(buf[i] == '\\') {
      push(&st1, i);
    } else if(buf[i] == '/') {
      if(size(&st1) > 0) {
    int sum = 0;
    j = pop(&st1);
    ans += i - j;
    sum += i - j;
    while(size(&st2) > 0) {
      int top2 = pop(&st2), top3 = pop(&st3);
      if(top2 < j) {
        push(&st2, top2);
        push(&st3, top3);
        break;
      }
      sum += top3;
    }
    push(&st2, j);
    push(&st3, sum);
      }
    }
  }
  while(size(&st3) > 0) {
    push(&st4, pop(&st3));
    cnt++;
  }
  printf("%d\n%d", ans, cnt);    
  for(i = 0; i < cnt; i++) {
    printf(" %d", pop(&st4));
  }
  puts("");
   
  return 0;
}