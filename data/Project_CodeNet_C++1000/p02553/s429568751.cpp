#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long int ll;
ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ios;
	ll a,b,c,d,ed;
	cin>>a>>b>>c>>d;
	ed=a*c;
	ed=max(ed,a*d);
	ed=max(ed,b*d);
	ed=max(ed,b*c);
	cout<<ed<<'\n';
}