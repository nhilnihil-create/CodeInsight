#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<utility>
#include<queue>
#include<stack>
#define pi 3.14159
#define Inf (int)pow(2., 12.)

using namespace std;
typedef std::pair<int, int> mypair;
queue<mypair> qu;
#define M 1000000

 
int main(){
	string str;
	char c;
	while(getline(cin, str)) {
		if(str == ".") { break; }
		stack<char> st;
		for(int i = 0; i < str.size(); i++) {
			if(str[i] == '(') { st.push('(');}
			else if(str[i] == '[') { st.push('[');}
			else if(str[i] == ')') {
				if(st.empty()) {
					st.push(')');
					break;
				}
				c = st.top();
				if(c == '(') {st.pop();}
				else {
					break;
				}
			}
			else if(str[i] == ']') {
				if(st.empty()) {
					st.push(']');
					break;
				}
				c = st.top();
				if(c == '[') {st.pop();}
				else {
					break;
				}
			}
		}
		if(st.empty()) { cout << "yes" <<endl;}
		else { cout << "no" <<endl;}
	}
	
}