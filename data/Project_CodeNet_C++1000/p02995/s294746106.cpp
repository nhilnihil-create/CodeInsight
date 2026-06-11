#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int a,b,c,d;
	cin>>a>>b>>c>>d;

	int cd=(c*d)/__gcd(c,d);


	int l,r,cc,dd,cdd;
	l=((a+c-1)/c)*c; r=(b/c)*c;
	cc=max(0LL, (r-l+c)/c);
	l=((a+d-1)/d)*d;r=(b/d)*d;
	dd=max(0LL,(r-l+d)/d);
	l=((a+cd-1)/cd)*cd;r=(b/cd)*cd;
	cdd=max(0LL,(r-l+cd)/cd);
	int tot=b-a+1;


	int div=cc+dd - cdd;
	cout<<tot-div;
	
}