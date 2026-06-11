#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  Node *n;
  Node *p;
};

Node *nill;

Node init(){
  nill = new Node;
  nill->n = nill;
  nill->p = nill;
}

Node insert_node(int k){
  Node *x = new Node;
  x->key = k;

  x->n = nill->n;
  nill->n->p = x;
  nill->n = x;
  x->p = nill;
}

Node* search_node(int k){
  Node *se = nill->n;
  while(1){
    if(se == nill) break;
    if(se->key == k) break;
    se = se->n;
  }
  return se;
}

void delete_node(Node *k){
  if(k == nill) return;
  k->p->n = k->n;
  k->n->p = k->p;
  delete k;
}

void deleteLast(){
  delete_node(nill->p);
}

void deleteFirst(){
  delete_node(nill->n);
}

void print_node(){
  Node *pri = nill->n;
  bool flag = false;
  while(1){
    if(pri == nill) break;
    if(flag) cout << " ";
    cout << pri->key;
    pri = pri->n;
    flag = true;
  }
  cout << endl;
}

int main(){
  init();
  ios::sync_with_stdio(false);


  int n;
  string str;
  cin >> n;

  for(int i = 0; i < n; i++){
    int k;
    cin >> str;
    if(str == "insert"){
      cin >> k;
      insert_node(k);
    }else if(str == "delete"){
      cin >> k;
      delete_node(search_node(k));
    }else if(str == "deleteFirst"){
      deleteFirst();
    }else if(str == "deleteLast"){
      deleteLast();
    }
  }
  print_node();

}