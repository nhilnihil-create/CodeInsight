#include<bits/stdc++.h>
using namespace std;
struct XY
{
	int x;
	int y;
};
int main ()
{
	string a;
	getline(cin,a);
	while(a!=".")
	{
		bool ok = false;
		stack<int> x;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='(')x.push(1);
			if(a[i]==')')
			{
				if(x.empty())
				{
					ok =true;
				}
				else if(x.top()==1)
					x.pop();
				else 
					ok = true;
			}
			if(a[i]=='[')x.push(2);
			if(a[i]==']')
			{
				
				if(x.empty())
				{
					
					ok = true;
				}else 
				if(x.top()==2)
					x.pop();
				else ok = true;
			}
		}
		if(x.empty()&&!ok)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		getline(cin,a);
	}
}