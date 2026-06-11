#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 1000001
using namespace std;

class element{
private:
	int key;
	element *next;
	element *previous;

public:
	element(int K,element *N,element *P){
		key = K;
		next = N;
		previous = P;
	}

	int getKey(){
		return key;
	}

	element(int K){
		key = K;
	}

	element *getNext(){
		return next;
	}

	element *getPrevious(){
		return previous;
	}

	void setNext(element *N){
		next = N;
	}

	void setPrevious(element *P){
		previous = P;
	}
};

class DoublyLinkedList{
private:
	element *head;
	element *tail;
	int num_of_elements;
public:
	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
		num_of_elements = 0;
	}
	int num(){
		return num_of_elements;
	}

	element *getHead(){
		return head;
	}

	element *getTail(){
		return tail;
	}

	void insertx(int x){
		if(num_of_elements == 0){
			element *X;
			X = new element(x);
			X->setNext(X);
			X->setPrevious(X);
			num_of_elements++;
			head = X;
			tail = X;
		}else{//num_of_elements > 0
			element *X;
			X = new element(x);
			//こっからの書き順がちょっと複雑！
			head->setNext(X);
			tail->setPrevious(X);
			X->setNext(tail);
			X->setPrevious(head);
			num_of_elements++;
			head = X;
		}
	}

	
	void deleteFirst(){
		if(num_of_elements == 1){
			delete head;//head == tail
			tail = NULL;
			num_of_elements--;
		}else{
			element *next_head = head->getPrevious();
			next_head->setNext(tail);
			tail->setPrevious(next_head);
			delete head;
			head = next_head;
			num_of_elements--;
		}
	}

	void deleteLast(){
		if(num_of_elements == 1){
			delete tail;//tail == head
			tail = NULL;
			num_of_elements--;
		}else{
			element *next_tail = tail->getNext();
			next_tail->setPrevious(head);
			head->setNext(next_tail);
			delete tail;
			tail = next_tail;
			num_of_elements--;
		}
	}

	void deletex(int x){
		element *pos = head;
		while(true){
			if(pos->getKey() == x){
				if(pos == head){
					//delete pos;←これやるとheadがdeleteされる
					deleteFirst();
					return;
				}else if(pos == tail){
					//delete pos;
					deleteLast();
					return;
				}else{
					(pos->getNext())->setPrevious(pos->getPrevious());
					(pos->getPrevious())->setNext(pos->getNext());
					delete pos;
					num_of_elements--;
					return;
				}
			}else/*(pos->getKey() != x)*/{
				if(pos == tail){
					//cout <<"error:no such element" <<endl;
					return;
				}else{
					pos = pos->getPrevious();//nextでないことに注意！
				}
			}
		}
	}

};
int main(){
	DoublyLinkedList DLL;

	int num_of_input;
	char input_string[20];
	int input_num;
	cin >>num_of_input;

	for(int i=0;i<num_of_input;i++){
		scanf("%s",&input_string);
		if(input_string[0] == 'i'){
			scanf("%d",&input_num);
			DLL.insertx(input_num);
		}else if(input_string[6] =='F'){
			DLL.deleteFirst();
		}else if(input_string[6] == 'L'){
			DLL.deleteLast();
		}else{
			scanf("%d",&input_num);
			DLL.deletex(input_num);
		}
	}

	element *pos = DLL.getHead();
	for(int i=0;i<num_of_input;i++){
		if(pos == DLL.getTail()){
			cout <<pos->getKey() <<endl;
			break;
		}else{
			cout <<pos->getKey() <<" ";
			pos = pos->getPrevious();
		}
	}
	
	return 0;
}
//とりあえず挿入だけは一回やった