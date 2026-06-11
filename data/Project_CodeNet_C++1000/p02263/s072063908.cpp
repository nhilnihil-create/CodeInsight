#include <iostream>
#include<stdio.h>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<int>a;
	string b;
	int kotae = 0;
	while (cin >> b) {
		if (isdigit(b[0]) == true) {
			a.push(stoi(b));
		}
		else {
				int aa=0, bb=0 ;
				aa = a.top();
				a.pop();
				bb = a.top();
				a.pop();
			if (b == "+") {
				a.push(aa + bb);
			}
			else if (b == "*") {
				a.push(aa*bb);
			}
			else if (b == "-") {
				a.push(bb-aa);
			}
		}
	}
cout<<a.top()<<endl;
	return 0;
}