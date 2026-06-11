#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,d,maxx;
	cin>>a>>b>>c>>d;
	maxx=max(a*c,a*d);
	maxx=max(maxx,max(b*c,b*d));
	cout<<maxx;
	return 0;
}