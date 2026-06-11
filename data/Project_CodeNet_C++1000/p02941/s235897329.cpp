#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	ll n;cin >> n;
	vector<ll> a(n);REP(i, n)cin >> a[i];
	vector<ll> b(n);REP(i, n)cin >> b[i];

	priority_queue<P> pq;
	REP(i, n)if(b[i] > a[i])pq.push(MP(b[i], i));
	ll ans = 0;

	while(!pq.empty()){
		auto now = pq.top();pq.pop();
		ll id = now.SE;
		ll num = now.FI - a[id];
		ll mai = b[(id+1)%n] + b[(id+n-1)%n];
		ans += num / mai;
		num %= mai;
		if(b[id] == a[id] + num){
			cout << -1 << endl;
			return 0;
		}
		b[id] = a[id] + num;
		if(num != 0){
			pq.push(MP(a[id]+num, id));
		}
	}

	cout << ans << endl;

	return 0;
}
