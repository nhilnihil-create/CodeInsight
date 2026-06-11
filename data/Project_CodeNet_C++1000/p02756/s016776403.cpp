#include<bits/stdc++.h>
using namespace std;
 
int main(){
  bool reversed = false;
  deque<char>deq;
  string s;
  cin>>s;
  for(int i=0; s[i]; i++) deq.push_back(s[i]);
  int q;
  cin>>q;
  while(q--){
  	int t;
  	cin>>t;
  	if(t==1) reversed = !reversed;
	else{
		int f;
		char ch;
		cin>>f>>ch;
		if(f==1){
			if(reversed) deq.push_back(ch);
			else deq.push_front(ch);
		}
		else{
			if(reversed) deq.push_front(ch);
			else deq.push_back(ch);
		}
	}
  }
  if(!reversed){
	  while(deq.size()){
	  	cout<<deq.front();
	  	deq.pop_front();
	  }
	}
	else{
		while(deq.size()){
			cout<<deq.back();
			deq.pop_back();
		}
	}
  
}