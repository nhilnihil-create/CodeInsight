#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int main() {
	ll a,b,c,d; cin >> a >> b >> c >> d;
	ll ans;
	ll e=a*c;
	ll f=a*d;
	ll g=b*c;
	ll h=b*d;
	ans=max(e,f);
	ans=max(ans,g);
	ans=max(ans,h);
	cout << ans << endl;
}