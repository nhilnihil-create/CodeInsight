#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

string solve(string s)
{
	stack<char> _stack;
	rep(i, 0, s.length())
	{
		switch (s[i])
		{
		case '(':
		case '[':
			_stack.push(s[i]);
			break;

		case ')':
			if (_stack.empty()) return "no";
			if (_stack.top() != '(') return "no";
			_stack.pop();
			break;

		case ']':
			if (_stack.empty()) return "no";
			if (_stack.top() != '[') return "no";
			_stack.pop();
			break;
		}
	}
	if (_stack.empty())
		return "yes";
	else
		return "no";
}

int main()
{
	while (1)
	{
		string s;
		getline(cin, s);
		if (s.length() == 1) return 0;

		cout << solve(s) << endl;
	}
}