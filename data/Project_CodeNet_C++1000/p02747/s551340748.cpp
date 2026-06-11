#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<s.length();i++)
	{
		if(i%2==0)
		{
			if(s[i]!='h')
			{
				flag=1;
				break;
			}
		}
		else
		{
			if(s[i]!='i')
			{
				flag=1;
				break;
			}
		}
	}
  	if(s.length()%2!=0)
    {
      cout<<"No"<<endl;
    }
	else if(flag==1)
	{
		cout<<"No"<<endl;
	}
	else
	{
		cout<<"Yes"<<endl;
	}
}