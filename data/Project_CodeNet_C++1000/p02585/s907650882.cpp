#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i,n){
		cin >> p[i];
		--p[i];
	}
	vector<ll> c(n);
	rep(i,n) cin >> c[i];
	ll ans = -INF;
	rep(i,n){
		vector<int> loop;
		int cur = i;
		ll sum = 0;
		while(true){
			cur = p[cur];
			loop.push_back(c[cur]);
			sum += c[cur];
			if(cur == i) break;
		}
		ll sz = loop.size();
		ll score = 0;
		rep(j,sz){
			score += loop[j];
			if(k <= j) break;
			ll cmp = score;
			if(sum >= 0) cmp += sum * ((k - (j+1)) / sz);
			chmax(ans, cmp);
		}
	}
	cout << ans << endl;
	return 0;
}
