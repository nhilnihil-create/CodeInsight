//できるだけ単純に実装する
//c++での文字列の扱い方も難しい．
//c++でも文字列を扱うときはchar[]を使った方がなにをやってるか
//明確になるのでバグも減るかも
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#define LEN 100005
using namespace std;

//new演算子の役割は動的確保を行うこと

/*通常のキュー
class Queue{
private:
	vector<string> s_v;
	vector<int> t_v;
public:
	//void enqueue(string s,int t);
	//string dequeue_name();
	//int dequeue_time();
	//bool isEmpty();
	//bool isFull();


	void enqueue(string s,int t){
	s_v.push_back(s);
	t_v.push_back(t);
	}

	string dequeue_name(){
		string tmp;
		tmp = *s_v.begin();
		s_v.erase(s_v.begin());
		return tmp;
	}

	int dequeue_time(){
		int tmp;
		tmp = *t_v.begin();
		t_v.erase(t_v.begin());
		return tmp;
	}

	bool isEmpty(){
		return s_v.empty();
	}
};
*/
class process{
public:
	string name;
	int time_wanted;

	process(string s,int t){
		name = s;
		time_wanted = t;
	}
};
/*リングバッファ*/
class Queue{
private:
	process *prcsQ[LEN];
	int top;
	int tail;
public:

	Queue(){
		this->top=0;
		this->tail=1;
	}

	void first_enqueue(process *p){
		prcsQ[0] = p;
	}
	
	void enqueue(process *p){
		prcsQ[tail] = p;
		tail = (tail + 1) % LEN;
		//cout <<tail <<endl;
	}

	process * dequeue(){
		int oldtop = top;
		top = (top + 1) % LEN;
		//cout <<top <<endl;
		return prcsQ[oldtop];
	}

	bool isEmpty(){
		if(top == tail)
			return true;
		return false;
	}
};

int main(){
	int process_num;
	int qwantum;
	string tmp_name;
	int tmp_time;
	int current_time = 0;
	char tmp_charsq[100];


	scanf("%d%d",&process_num,&qwantum);//scanfの用法

	Queue queue;

	for(int i=0;i<process_num;i++){
		scanf("%s%d",tmp_charsq,&tmp_time);
		//まずCでサポートされているchar[]に代入し，char[]をstringに代入するという形式にする
		tmp_name = tmp_charsq;
		process *p = new process(tmp_name,tmp_time);
		if(i==0)
			queue.first_enqueue(p);
		else
			queue.enqueue(p);
	}
	
	while(true){
		process *alt;
		alt = queue.dequeue();
		if(alt->time_wanted <= qwantum){
			current_time = current_time + alt->time_wanted;
			cout <<alt->name <<" " <<current_time << endl;
			delete alt;
			if(queue.isEmpty())
				return 0;
		}else{
			current_time = current_time + qwantum;
			alt->time_wanted = alt->time_wanted - qwantum;
			queue.enqueue(alt);
		}
	}

	return 0;
}