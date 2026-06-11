#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll m, d, c;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> m;
	ll sum = 0;
	ll ans = -1;
	rep(i, 1, m){
		cin >> d >> c;
		sum += d*c;
		ans += c;
	}
	ans += (sum-1)/9;
	print(ans)
	return 0;
}