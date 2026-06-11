#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	int n,i,f=0;
	string s;
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
		{
			if(i%2==0&&s[i]!='U'&&s[i]!='D')
			{
				if(s[i]!='R')
					{
						f=1;
						break;
					}
			}
				
			else if(i%2!=0&&s[i]!='U'&&s[i]!='D')
				{
					if(s[i]!='L')
						{
							f=1;
							break;
						}
					}	
				
		}
	if(f==0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}