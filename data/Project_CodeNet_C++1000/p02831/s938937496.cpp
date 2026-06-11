#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b;
	cin>>a>>b;
	long int ans1;
	ans1=__gcd(a,b);;
	unsigned long long int ans= a*b;
	ans=ans/ans1;
	cout<<ans<<endl;
}