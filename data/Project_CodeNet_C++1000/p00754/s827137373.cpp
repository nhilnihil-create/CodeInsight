#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	while (true)
	{
		string str = "";
		while (true)
		{
			char ch = cin.get();
			if (ch == '\n')
				continue;
			if (ch == '.')
				break;
			str.push_back(ch);
		}
		if (str.empty())
			break;
		stack<char> S;
		bool flag = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				S.push(str[i]);
			else if (str[i] == ')')
				if (S.empty() || S.top() != '(')
					flag = false;
				else
					S.pop();
			else if (str[i] == ']')
				if (S.empty() || S.top() != '[')
					flag = false;
				else
					S.pop();
		}
		if (!S.empty())
			flag = false;
		cout << (flag ? "yes" : "no") << endl;
	}
}
