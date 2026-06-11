#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
string s;
bool ischar(char c){
	if('a'<=c && c<='z') return true;
	if('A'<=c && c<='Z') return true;
	if(c==' ') return true;
	return false;
}
bool solve(){
	stack<int> st;
	for(int i=0;i<s.size();i++){
		if(ischar(s[i])) continue;
		if(s[i]=='(') st.push(0);
		if(s[i]=='[') st.push(1);
		if(s[i]==')'){
			if(st.empty()) return 0;
			int s=st.top();
			st.pop();
			if(s==1) return 0;
		}
		if(s[i]==']'){
			if(st.empty()) return 0;
			int s=st.top();
			st.pop();
			if(s==0) return 0;
		}
		if(s[i]=='.'){
			if(st.empty()) return 1;
			else return 0;
		}
	}
	return 1;
}
int main(){
	while(true){
		getline(cin,s);
		if(s[0]=='.') break;
		if(solve()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}