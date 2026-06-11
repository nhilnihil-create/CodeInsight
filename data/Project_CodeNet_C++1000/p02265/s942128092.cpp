#include<iostream>
using namespace std;

class Node{
 public:
  Node* prev;
  Node* next;
  int data;
  Node(){prev = 0; next = 0; data = 0;}
};

class List{
 private:
  Node head;
 public:
  List(){head.prev = &head; head.next = &head;}
  int insert(int x){
   Node* p = new Node();
   if(p==0) return -1;
   Node* q = &head;
   Node* r = head.next;
   p->prev = q;
   p->next = r;
   p->data = x;
   q->next = p;
   r->prev = p;
   return 0;
  }
  int del(int x){
   Node* p;
   for(p=head.next; p!=&head; p=p->next){
    if(p->data==x) break;
   }
   if(p==&head) return -2;
   Node* q = p->prev;
   Node* r = p->next;
   q->next = r;
   r->prev = q;
   delete p;
   return 0;
  }
  int deleteFirst(){
   Node* p = head.next;
   if(p==&head) return -2;
   Node* q = p->prev;
   Node* r = p->next;
   q->next = r;
   r->prev = q;
   delete p;
   return 0;
  }
  int deleteLast(){
   Node* p = head.prev;
   if(p==&head) return -2;
   Node* q = p->prev;
   Node* r = p->next;
   q->next = r; 
   r->prev = q;
   delete p;
   return 0;
  }
  void print(){
   for(Node* p=head.next; p!=&head; p=p->next){
    cout << p->data;
    if(p->next!=&head){
     cout << ' ';
    }else{
     cout << endl;
    }
   } 
  }
};

int main(){
 List L;
 int n;
 cin >> n;
 for(int i=0; i<n; i++){
  char com[20];
  cin >> com;
  if(com[0]=='i'){
   int x;
   cin >> x;
   L.insert(x);
  }else if(com[6]=='F'){
   L.deleteFirst();
  }else if(com[6]=='L'){
   L.deleteLast();
  }else{
   int x;
   cin >> x;
   L.del(x);
  }
 }
 L.print();
 return 0;
}