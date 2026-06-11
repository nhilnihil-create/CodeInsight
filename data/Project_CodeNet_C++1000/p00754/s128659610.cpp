#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	while (true)
	{
		string target;
		getline(cin, target);
		if (target == ".") break;
		stack<char> hako;
		bool flag = true;
		for (int i = 0; i < target.size(); i++)
		{
			if (target[i] == '(')
			{
				hako.push('(');
			}
			else if(target[i] == '['){
				hako.push('[');
			}
			else if (target[i] == ')')
			{
				if (!hako.empty() && hako.top() == '(')
				{
					hako.pop();
				}
				else {
					cout << "no" << endl;
					flag = false;
					break;
				}
			}
			else if (target[i] == ']')
			{
				if (!hako.empty() && hako.top() == '[')
				{
					hako.pop();
				}
				else {
					cout << "no" << endl;
					flag = false;
					break;
				}
			}
		}
		if (hako.empty() && flag)
		{
			cout << "yes" << endl;
		}
		else if(flag){
			cout << "no" << endl;
		}
	}
	return 0;
}