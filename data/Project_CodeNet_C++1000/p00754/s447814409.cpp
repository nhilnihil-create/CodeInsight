#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	while(getline(cin,str), str!=".")
	{
		bool ok=true;
		stack<char> s;
		for(int i=0; i<str.size(); i++)
		{
			if(str[i]=='(' || str[i]=='[')
			{
				s.push(str[i]);
			}
			else if(str[i]==')')
			{
				if(s.empty())    { ok=false; break; }
				if(s.top()!='(') { ok=false; break; }
				s.pop();
			}
			else if(str[i]==']')
			{
				if(s.empty())    { ok=false; break; }
				if(s.top()!='[') { ok=false; break; }
				s.pop();
			}
			else if(str[i]=='.')
			{
				break;
			}
		}

		if(!s.empty()) { ok=false; }

		cout << (ok?"yes":"no") << endl;
	}
}