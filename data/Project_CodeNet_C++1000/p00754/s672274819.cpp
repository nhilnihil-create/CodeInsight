#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string line;
	while (getline(cin,line) && line != ".")
	{
		stack<char> st;
		bool flag = true;
		for (int i = 0; i < line.size(); i++)
		{
			char c = line.at(i);
			if ((c == ']' || c == ')') && st.size() < 1)
			{
				flag = false;
				break;
			}
			if (c == ']')
			{
				if (st.top() == '[')
				{
					st.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
			else if (c == ')')
			{
				if (st.top() == '(')
				{
					st.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
			else if (c == '[')
			{
				st.push(c);
			}
			else if (c == '(')
			{
				st.push(c);
			}
		}

		if (st.size() > 0)flag = false;

		if (flag)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}