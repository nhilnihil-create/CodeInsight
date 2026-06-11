#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<200;i++)
	{
		c-=b;
		if(c<=0&&a>0)
		{
			cout<<"Yes";
			return 0;
		}
		a-=d;
		if(a<=0&&c>0)
		{
			cout<<"No";
			return 0;
		}
    }
}