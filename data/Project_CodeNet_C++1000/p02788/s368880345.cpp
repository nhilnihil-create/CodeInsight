#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	ll n, d, a;
	cin >> n >> d >> a;
	vector<pair<ll, ll>> fox(n);
	rep(i,n) cin >> fox[i].first >> fox[i].second;
	sort(fox.begin(), fox.end());
	ll tot = 0;
	ll ans = 0;
	queue<pair<ll, ll>> q;
	rep(i,n){
		ll x = fox[i].first;
		ll h = fox[i].second;
		while(q.size() && q.front().first < x){
			tot -= q.front().second;
			q.pop();
		}
		h -= tot;
		if(h > 0){
			ll num = (h+a-1)/a;
			ans += num;
			ll damage = num*a;
			tot += damage;
			q.emplace(x+2*d, damage);
		}
	}
	cout << ans << endl;
}