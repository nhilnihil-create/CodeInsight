#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double
#define rep(i, x, n, j) for(int i=x;i<(int)n;i+=j)
#define F first
#define S second
#define per(i, x, n, j) for(int i=(int)n-1;i>=0;i-=j)
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()

const int N = 2000100;
const ll MOD = 1e9+7;
const ll inf = 1e18+5;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int _;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y, a, b, c; cin >> x >> y >> a >> b  >> c;
	ll r[a], g[b], co[c];
	rep(i,0,a,1) cin >> r[i];
	rep(i,0,b,1) cin >> g[i];
	rep(i,0,c,1) cin >> co[i];
	vector<pair<ll, char>> v;
	rep(i,0,a,1) v.push_back({r[i], 'R'});
	rep(i,0,b,1) v.push_back({g[i], 'G'});
	rep(i,0,c,1) v.push_back({co[i], 'C'});
	sort(all(v));
	ll red=x, green=y, col=0;
	reverse(all(v));
	ll ans = 0;
	for(int i=0; i<sz(v); ++i){
		if(red+green-col<=0) break;
		ll amount = v[i].F, type = v[i].S;
		if(type=='R' && red>0){
			ans += amount; --red;
		}
		if(type=='G' && green>0){
			ans += amount; --green;
		}
		if(type=='C'){
			ans += amount; ++col;
		}
	}
	cout << ans << endl;
	return 0;
}
