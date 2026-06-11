#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;
ll lim=1e18;

int main() {
	int n; cin >> n;
	vint a(n);
	rep(i,n) cin >> a[i];
	int now=1;
	int ans=0;
	rep(i,n) {
		if(a[i]!=now) ans++;
		if(a[i]==now) now++;
	}
	if(now==1) cout << -1 << endl;
	else cout << ans << endl;
}