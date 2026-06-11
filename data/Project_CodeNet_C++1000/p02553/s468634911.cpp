#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,c,d,cnt=0;
	cin>>a>>b>>c>>d;
	if(a<0)
	cnt++;
	if(b<0)
	cnt++;
	if(c<0)
	cnt++;
	if(d<0)
	cnt++;
	if(cnt==0 || cnt==1)
	cout<<b*d<<endl;
	else if(cnt==3)
	cout<<c*a<<endl;
	else if(cnt==4)
	cout<<a*c<<endl;
	else
	{
		if(c>=0 && d>=0)
		cout<<b*c<<endl;
		else if(b>=0 && d>=0)
		{
			if(b*d>a*c)
			cout<<b*d<<endl;
			else
			cout<<a*c<<endl;
		}
		else
		cout<<d*a<<endl;
	}
	return 0;
}