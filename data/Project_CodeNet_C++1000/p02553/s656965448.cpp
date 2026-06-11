#include<bits/stdc++.h>
using namespace std;
long long max_(long long a,long long b)
{
	if(b>a)
	return b;
	else
	return a;
}
int main()
{
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long a1=a*c,a2=a*d,a3=b*c,a4=b*d;
	long long ans=max_(a1,max_(a2,max_(a3,a4)));
	cout<<ans<<endl;
	return 0;
}