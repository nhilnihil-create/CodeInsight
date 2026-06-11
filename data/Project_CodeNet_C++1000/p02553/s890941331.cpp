#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 3e18;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a,b,c,d;

	cin>>a>>b>>c>>d;

	ll ans = -inf;

	ans=max(ans,a*c);
	ans=max(ans,a*d);
	ans=max(ans,b*c);
	ans=max(ans,b*d);

	cout<<ans<<'\n';
	
	return 0;
}