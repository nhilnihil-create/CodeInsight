#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
#include<cstdlib>
//#include<cmath>
using namespace std;

int main(void)
{
	string s;
	int a,b,m;
	stack<int>A;
	while (cin >> s) {
		switch (static_cast<char>(s[0])) {
			case '+':a = A.top(); A.pop(); b = A.top(); A.pop(); m = a + b; A.push(m); break;
			case '-':a = A.top(); A.pop(); b = A.top(); A.pop(); m = b - a; A.push(m); break;
			case '*':a = A.top(); A.pop(); b = A.top(); A.pop(); m = a * b; A.push(m); break;
			default:A.push(atoi(s.c_str()));
		}
	}
	cout << A.top() << endl;
	return 0;
}
