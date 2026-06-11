#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

bool solve(const string &s){
	stack<char> x;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '[' || s[i] == '('){
			x.push(s[i]);
		}
		else if(s[i] == ']'){
			if(x.empty() || x.top() != '[')
				return false;
			x.pop();
		}
		else if(s[i] == ')'){
			if(x.empty() || x.top() != '(')
				return false;
			x.pop();
		}
	}
	return x.empty();
}

int main(){
	string s;
	while(getline(cin, s), s != "."){
		puts(solve(s) ? "yes" : "no");
	}
}