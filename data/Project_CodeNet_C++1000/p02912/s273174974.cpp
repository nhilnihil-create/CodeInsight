#include "bits/stdc++.h"
//#include "atcoder/all"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
//using namespace atcoder;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	priority_queue<ll> pq;
	rep(i,n){
		ll a;
		cin >> a;
		pq.push(a);
	}
	rep(i,m){
		ll b = pq.top();
		b /= 2;
		pq.pop();
		pq.push(b);
	}
	ll ans = 0;
	rep(i,n){
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
	return 0;
}
