#include <iostream>
#include <stack>
#include <string>

using namespace std;

const string Terminater = ".";

bool isOK(string& str)
{
	stack<char> st;
	for (char& c : str)
	{
		if (c == '(' || c == '[')
			st.push(c);

		if (c == ')')
		{

			if ( !st.empty() && '(' == st.top())
				st.pop();
			else
				return false;
		}
		else if (c == ']')
		{
			if (!st.empty() && '[' == st.top())
				st.pop();
			else
				return false;
		}
	}

	if (st.empty())
		return true;

	return false;
}

int main()
{
	while (1)
	{
		string str;
		getline(cin, str);

		if (str == Terminater)
			break;

		if (isOK(str))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}