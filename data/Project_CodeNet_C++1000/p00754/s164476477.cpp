#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (true)
	{
		getline(cin, s);
		if (s == ".")	break;

		stack<int> data, data2;
		
		for (auto && x : s)
		{
			if (x == '[')
				data.emplace(data2.size());
			else if (x == ']')
			{
				if (data.empty())
				{
					cout << "no" << endl;
					goto END;
				}
				else if (data2.size() != data.top())
				{
					cout << "no" << endl;
					goto END;
				}

				data.pop();
			}
			else if (x == '(')
				data2.emplace(data.size());
			else if (x == ')')
			{
				if (data2.empty())
				{
					cout << "no" << endl;
					goto END;
				}
				else if (data.size() != data2.top())
				{
					cout << "no" << endl;
					goto END;
				}
				data2.pop();
			}
		}

		if (data.empty() && data2.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	END:;

	}

	return 0;
}