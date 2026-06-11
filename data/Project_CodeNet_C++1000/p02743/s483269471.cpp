#include<bits/stdc++.h>
#define stpn setprecision
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,d;
	cin>>a>>b>>c;
	d=c-a-b;
	if (d>0&&4*a*b<d*d) cout<<"Yes";
	else cout<<"No";
	return 0;
}
