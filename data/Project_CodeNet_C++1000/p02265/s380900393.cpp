#include <iostream>
#include "string.h"
using namespace std;

class Node{
	public:
		Node* prev;
		Node* next;
		int data;
		Node(){ prev=0; next=0; data=0;}
};

class List{
	private:
		Node head;
	public:
		List(){ head.prev=&head; head.next=&head;}
		int insertx(int x);
		int deletex(int x);
		int deleteFirst();
		int deleteLast();
		int print();
};

//ここに問題がある！！
int List::insertx(int x){
	Node* p=new Node();
	if(p==0)
		return -1;

	Node* q=head.next;
	Node* r=&head;
	
	p->prev=r;
	p->next=q;
	p->data=x;

	r->next=p;
	q->prev=p;
	
	return 0;
}

int List::deletex(int x){
	for(Node* p=head.next; p!=&head; p=p->next){
		if(p->data==x){
			Node* q=p->prev;
			Node* r=p->next;

			q->next=r;
			r->prev=q;

			delete p;

			return 0;
		}
		
	}
	return -2;
}
int List::deleteFirst(){
	Node* p=head.next;
	Node* q=&head;
	Node* r=p->next;
	
	if(p==q)
		return -3;	//何も入っていない

	q->next=r;
	r->prev=q;	
	
	delete p;
		return 0;
}

int List::deleteLast(){
	Node* p=head.prev;
	Node* q=&head;
	Node* r=p->prev;
	
	if(p==q)
		return -3;	//何も入っていない

	q->prev=r;
	r->next=q;	
	
	delete p;
		return 0;
}

int List::print(){
	for(Node* p=head.next; p!=&head; p=p->next){
		if(p!=head.prev)
			cout << p->data <<' ';
		else
			cout << p->data << endl;
	}
	
}

int main(){
	List L;
	int n,x;
	char a[12];
	cin>>n;

	for(int i=0; i<n; i++){
		cin >> a;

		if(a[0]=='i'){
			cin >>x;
			L.insertx(x);
		}
		else if(a[6]=='F'){
			L.deleteFirst();
		}
		else if(a[6]=='L'){
			L.deleteLast();
		}
		else{
			cin >>x;
			L.deletex(x);
		}
	}
	L.print();
	return 0;
}


	
		 