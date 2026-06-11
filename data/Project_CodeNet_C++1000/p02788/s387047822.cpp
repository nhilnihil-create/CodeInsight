#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll n, d, a;
	cin >> n >> d >> a;
	vector<P> p(n);
	rep(i,n){
		cin >> p[i].first >> p[i].second;
		p[i].second = (p[i].second + a - 1) / a; // 何回殴れば倒せるかに変換する
	}
	sort(p.begin(),p.end());
	d = d*2;
	ll tot = 0;
	queue<pair<ll,ll>> q;
	ll ans = 0;
	rep(i,n) {
		ll x = p[i].first;
		ll h = p[i].second;
		while (q.size() && q.front().first < x){
			tot -= q.front().second;
			q.pop();
		}
		h -= tot;
		if (h > 0) {
			ll num = h;
			ans += h;
			ll damage = num;
			tot += damage;
			q.emplace(x+d, damage);
		}
	}
	cout << ans << endl;
}
