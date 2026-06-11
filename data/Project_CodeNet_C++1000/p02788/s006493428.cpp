#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))
 
using namespace std;
 
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-12;
const double PI = acos(-1.0);

int main() {
	ll n,d,a;
	cin >> n >> d >> a;
	vector<ll> v;
	vector<pair<ll,ll>> vv;
	rep(i,n){
		ll x,h;
		cin >> x >> h;
		v.push_back(x);
		vv.emplace_back(x,h);
	}
	v.push_back(MOD); v.push_back(MOD);
	sort(all(v));
	sort(all(vv));

	ll damage[n+10] = {},sum = 0;
	for(int i = 1; i <= n; i++){
		damage[i] += damage[i-1];
		ll now_h = vv[i-1].second-damage[i]*a;
		if(now_h <= 0) continue;
		ll cnt = (now_h-1)/a+1,range = v[i-1]+2*d;
		sum += cnt;
		damage[i] += cnt;
		damage[lower_bound(all(v),range+1)-v.begin()+1] -= cnt;
	}
	cout << sum << endl;
	return 0;
}