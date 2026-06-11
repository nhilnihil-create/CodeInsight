#include<bits/stdc++.h>
using namespace std;

string S;
long long Q;


int main(){
	cin >> S >> Q;

	bool rev = false;
	string head = "";
	string tail = "";


	for(long long i = 0; i < Q; i++) {
		long long op;
		cin >> op;
		if (op == 1) {
			rev = !rev;
		} else {
			long long tmp;
			char ch;
			cin >> tmp >> ch;

			if(tmp == 1) {
				if(rev) {
					tail += ch;
				} else {
					head += ch;
				}
			} else {
				if(rev) {
					head += ch;
				} else {
					tail += ch;
				}
			}
		}
	}


	if(rev) {
		reverse(tail.begin(), tail.end());
		cout << tail;
		reverse(S.begin(), S.end());
		cout << S;
		cout << head << endl;
	} else {
		reverse(head.begin(), head.end());
		cout << head;
		cout << S;
		cout << tail << endl;
	}
}
