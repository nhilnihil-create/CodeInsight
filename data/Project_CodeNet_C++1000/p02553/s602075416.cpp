#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;

int main()
{
	ll a,b,c,d;cin>>a>>b>>c>>d;
	ll ans=max(max(a*c,a*d),max(b*c,b*d));
	if((a<=0&&b>=0)||(c<=0&&d>=0)) cout<<max(ans,ll(0));
	else cout<<ans;
	return 0;	
} 