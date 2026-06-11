#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;


signed main(){
	//cout << fixed << setprecision(10);
	ll n; cin >> n;
	ll k; cin >> k;
	ll sum_lcm = 1;
	ll ng = 1;
	ll cnt = -1;
	rep(i,0,n){
		ll a; cin >> a;
		ng = (ng * a) / __gcd(ng,a);
		a /= 2;
		ll b = a;
		ll j = 0;
		while(b % 2 == 0){
			b /= 2;
			j++;
		}
		if(i == 0)cnt = j;
		else{
			if(cnt != j){
				cout << 0 << endl;
				return 0;
			}
		}
		sum_lcm = (sum_lcm*a) / __gcd(sum_lcm,a);
	}
	ll ans = k / sum_lcm - k / ng;
	cout << ans << endl;

	return 0;
}