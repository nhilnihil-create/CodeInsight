#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

void solve()
{
	string s;
	while (getline(cin, s))
	{
		if (s == ".")
		{
			return;
		}
		bool isBalanced = true;
		stack<char> Stack;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				Stack.push('(');
			}
			else if (s[i] == '[')
			{
				Stack.push('[');
			}
			else if (s[i] == ')')
			{
				if (Stack.empty())
				{
					isBalanced = false;
					break;
				}
				char c = Stack.top();
				Stack.pop();
				if (c != '(')
				{
					isBalanced = false;
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (Stack.empty())
				{
					isBalanced = false;
					break;
				}
				char c = Stack.top();
				Stack.pop();
				if (c != '[')
				{
					isBalanced = false;
					break;
				}
			}
		}
		if (isBalanced && Stack.size() == 0)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}