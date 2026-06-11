#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int q;
	cin>>q;
	deque<char>deq;
	for(int i=0; s[i]; i++) deq.push_back(s[i]);
	bool reversed = false;
	while(q--){
		int op;
		cin>>op;
		if(op==1) reversed = !reversed;
		if(op==2){
			int a;
			char b;
			cin>>a>>b;
			if(a==1){
				if(reversed) deq.push_back(b);
				else deq.push_front(b);
			}
			else{
				if(reversed) deq.push_front(b);
				else deq.push_back(b);
			}
		}
	}
	if(reversed){
		while(!deq.empty()){
			cout<<deq.back();
			deq.pop_back();
		}
	}
	else{
		while(!deq.empty()){
			cout<<deq.front();
			deq.pop_front();
		}
	}
}