#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool solve(string S)
{
	stack<char> s;

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(' || S[i] == '[')
		{
			s.push(S[i]);
		}

		if (S[i] == ')' || S[i] == ']')
		{
			if (s.empty()) { return false; }

			if (s.top() != (S[i] == ')' ? '(' : '['))
			{
				return false;
			}
			
			s.pop();
		}
	}

	return s.empty();
}

int main()
{
	string S;

	while (true)
	{
		S = "";

		while (S == "")
		{
			getline(cin, S);
		}

		if (S == ".") { break; }

		cout << (solve(S) ? "yes" : "no") << endl;
	}
	
	return 0;
}