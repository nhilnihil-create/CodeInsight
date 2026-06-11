#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <functional>
#include <algorithm>
using namespace std;
#include <stack>

//FILE * in = freopen("input.txt", "r" , stdin);
char data[1000];

int main() {
	
	while(true) {
		bool flag = false;
		gets(data);
		if(data[0] == '.' && data[1] == 0)break;
		int i = 0;
		stack<int> a;
		while(data[i] != '.'){
			switch(data[i])
			{
			case '(':
				a.push('(');
				break;
			case '[':
				a.push('[');
				break;
			case ')':
				if(a.empty()) {
					flag = true;
					goto out;
				}
				if(a.top() == '(')
					a.pop();
				else {
					flag = true;
					goto out;
				}
				break;

			case ']':
				if(a.empty()) {
					flag = true;
					goto out;
				}
				if(a.top() == '[')
					a.pop();
				else {
					flag = true;
					goto out;
				}
				break;
			default:
				break;
			}
			i++;
		}
		out:
		if(!flag && a.empty())
			puts("yes");
		else
			puts("no");
	}

	return 0;
}