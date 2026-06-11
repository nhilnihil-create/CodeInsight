#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s == ".") return 0;
		vector<char> ary;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '[') ary.push_back('[');
			if (s[i] == ']') ary.push_back(']');
			if (s[i] == '(') ary.push_back('(');
			if (s[i] == ')') ary.push_back(')');
		}
		int beforeSize = ary.size();
		while (true)
		{
			if (ary.size() == 0)
			{
				cout << "yes" << endl;
				break;
			}
			for (int i = 1; i < ary.size(); i++)
			{
				if ((ary[i - 1] == '[' && ary[i] == ']') ||
					ary[i - 1] == '(' && ary[i] == ')')
				{
					ary.erase(ary.begin() + i);
					ary.erase(ary.begin() + i - 1);
					i--;
				}
			}
			if (beforeSize == ary.size())
			{
				cout << "no" << endl;
				break;
			}
			beforeSize = ary.size();
		}
	}

	return 0;
} 