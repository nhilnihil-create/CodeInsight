#include<iostream>
#include<stack>
using namespace std;
string s;
main()
{
	while(getline(cin,s),s!=".")
	{
		stack<int>a,b;
		int ca=0,cb=0,f=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
			{
				ca++;
				a.push(cb);
			}
			else if(s[i]=='[')
			{
				cb++;
				b.push(ca);
			}
			else if(s[i]==')')
			{
				ca--;
				if(a.empty()||cb!=a.top())
				{
					cout<<"no"<<endl;
					f=1;
					break;
				}
				a.pop();
			}
			else if(s[i]==']')
			{
				cb--;
				if(b.empty()||ca!=b.top())
				{
					cout<<"no"<<endl;
					f=1;
					break;
				}
				b.pop();
			}
			if(ca<0||cb<0)
			{
				cout<<"no"<<endl;
				f=1;
				break;
			}
		}
		if(!f)
		{
			cout<<(ca||cb?"no":"yes")<<endl;
		}
	}
}

