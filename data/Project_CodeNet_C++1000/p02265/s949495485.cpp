#include<iostream>
#include<list>
#include<string>
using namespace std;

void Command(list<int> &X, string &c){
	if(c == "insert"){
		int d;
		cin >> d;
		X.push_front(d);
	}else if(c == "delete"){
		int d;
		cin >> d;
		list<int>::iterator itr = X.begin();
		while(*itr != d && itr != X.end()){
			itr++;
		}
		if(itr != X.end()){
			X.erase(itr);
		}
	}else if(c == "deleteFirst"){
		X.pop_front();
	}else if(c == "deleteLast"){
		X.pop_back();
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	list<int> X;
	for(int i = 0; i < n; i++){
		string c;
		cin >> c;
		Command(X, c);
	}
	list<int>::iterator it  = X.begin();
	list<int>::iterator end = X.end();
	end--;
	while(it != end){
		cout << *it << ' ';
		it++;
	}
	cout << *end << endl;
	return 0;
}