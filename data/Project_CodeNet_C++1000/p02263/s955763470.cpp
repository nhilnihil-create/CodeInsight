#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <cstdlib>
using namespace std;

#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
stack<int> s;
int main() {
	char str[8];
	while(1) {
		if(scanf("%s", str) == EOF) break;
		if(!strcmp(str,"*")) {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			s.push(a * b);
		} else if(!strcmp(str,"+")) {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			s.push(a + b);
		} else if(!strcmp(str,"-")) {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			s.push(b - a);
		} else {
			s.push(atoi(str));
		}
	}
	cout << s.top() << endl;
	return 0;
}