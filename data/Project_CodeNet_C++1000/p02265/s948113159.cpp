#include <bits/stdc++.h>
using namespace std;

struct node{

  int key;
  node *next, *prev;

};

node *nil;

void insert_node(int key){
  node *x = (node *)malloc(sizeof(node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

void delete_node(node *t){
  if(t == nil) return; 
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

node* seach_node(int key){
  node *seach = nil->next;
  while(1){
    if(seach->key == key) break;
    if ( seach == nil ) break;
    seach = seach->next;
  }
  return seach;
}

void malloc_node(){
  nil = (node *)malloc(sizeof(node));
  nil->next = nil;
  nil->prev = nil;
}



int main(){

  int n;
  char str[20];
  int key;

  scanf("%d", &n);

  malloc_node();

  for(int i = 0; i < n; i++){

    scanf("%s",str);
    if(str[0] == 'i' || strlen(str) == 6) scanf("%d",&key);

    // cout << str << " " << key << " " << i << " " << n << endl;


    if(str[0] == 'i'){
      insert_node(key);
    }else if(str[0] == 'd'){
      if(strlen(str) > 6){
	if(str[6] =='F') delete_node(nil->next);
	else if(str[6] == 'L') delete_node(nil->prev);
      }else delete_node(seach_node(key));
    }
    



  }
  
  node *ans = nil->next;
  int cnt = 0;
  while(ans != nil){
    if(cnt > 0) printf(" ");
    cnt++;
    printf("%d", ans->key);
    ans = ans->next;
  }
  printf("\n");


  return 0;

}