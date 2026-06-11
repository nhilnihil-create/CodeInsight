#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
using namespace std;


#define abs(N) ((N>0)?N:-1*N)
#define lt(A,B) ((A>B)?B:A)
#define gt(A,B) ((A<B)?B:A)
#define print(S) (cout << S)
#define println(S) (cout << S << endl)

template <typename T>
class queue{
public :
	const static int LEN = 1000000;
	queue<T>(){
		head = tail = 0;
	}

	void empty(){
		head = tail = 0;
	}

	bool isEmpty(){
		return (head == tail);
	}

	bool isFull(){
		return ((tail + 1)%LEN == head);
	}

	T dequeue(){
		if(isEmpty()){
			throw exception();
		}
		if(head == LEN - 1){
			head = 0;
			return body[LEN -1];
		}
		return body[head++];
	}

	void enqueue(T el){
		if(isFull()){
			throw exception();
		}
		if(tail == LEN -1){
			tail = 0;
			body[LEN-1] = el;
		}else{
			body[tail++] = el;
		}
	}

	T top(){
		if(isEmpty()){
			throw exception();
		}
		return body[head];
	}

private:
	T body[LEN];
	int head,tail;
};

typedef struct{
	string name;
	int time;
}process;

int main(){
	queue<process> que;
	int n ,q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		process p;
		cin >> p.name >> p.time;
		que.enqueue(p);
	}
	int t = 0;
	while(!que.isEmpty()){
		process p = que.dequeue();
		if(p.time>q){
			p.time -= q;
			que.enqueue(p);
			t += q;
		}else{
			t += p.time;
			cout << p.name << " " << t << endl;;
		}
	}

	return 0;
}

