#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	ll x1=a*c,x2=a*d,x3=b*c,x4=b*d;
	ll ans1=max(x1,x2),ans2=max(x3,x4);
	cout<<max(ans1,ans2)<<endl;
	return 0;
}

