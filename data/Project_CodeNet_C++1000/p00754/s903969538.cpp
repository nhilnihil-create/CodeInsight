#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

int main() {
	char c;
	int count,flag;
	stack<char> sta;
	while(1){
		count = 0;
		flag = 0;
		while(1){
			scanf("%c",&c);
			if(c == '.')break;
			if(flag == 1)continue;
			if(c == '('){
				sta.push(')');
			}
			else if(c == '['){
				sta.push(']');
			}
			else if(c == ')' || c == ']'){
				if(sta.size() == 0)flag = 1;
				else if(sta.top() != c)flag = 1;
				if(sta.size() > 0)sta.pop();
			}
			count++;
		}
	if(count == 1)break;
	if(flag == 0 && sta.size() == 0)cout << "yes" <<endl;
	else if(flag == 1 || sta.size() > 0)cout << "no" <<endl;
	while(sta.size() != 0){
		sta.pop();
	}
	}
	return 0;
}