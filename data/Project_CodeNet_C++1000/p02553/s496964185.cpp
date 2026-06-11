#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
long long max(long a,long b)
{
	return a>b?a:b;
}
int main()
{
	cin>>a>>b>>c>>d;
	cout<<max(max(a*c,a*d),max(b*c,b*d));
}