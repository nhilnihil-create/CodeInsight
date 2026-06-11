#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	for(;;)
	{
		stack<int> S;
		string str;
		getline(cin,str);
		if(str==".")break;
		int n=str.size();
		int f=0;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='(')
			{
				S.push(1);
			}
			else if(str[i]=='[')
			{
				S.push(0);
			}
			else if(str[i]==')')
			{
				if(S.empty())
				{
					f=1;
					break;
				}
				if(S.top()==1)
				{
					S.pop();
				}
				else
				{
					f=1;
					break;
				}
			}
			else if(str[i]==']')
			{
				if(S.empty())
				{
					f=1;
					break;
				}
				if(S.top()==0)
				{
					S.pop();
				}
				else
				{
					f=1;
					break;
				}
			}
		}
		if(!S.empty())f=1;
		if(f==1)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
	return 0;
}
