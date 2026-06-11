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
	ll n,m; cin >> n >> m;
	ll cnt = 0, cnt2 = 0;
	vector<bool> ok(n,0);
	map<ll,ll> mp;
	rep(i,0,m){
		ll p; string s; 
		cin >> p >> s;
		if(ok[p])continue;
		if(s == "AC"){
			ok[p] = 1;
			cnt++;
		}
		else mp[p]++;
	}
	for(auto c:mp){
		if(!ok[c.first])continue;
		cnt2 += c.second;
	}
	cout << cnt << " " << cnt2 << endl;

	return 0;
}