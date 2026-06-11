#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll ans = INF;
vector<vector<P>> G;
vector<P> e;
V c;

void bfs(ll s) {
	queue<ll> q;

	q.push(s);

	ll now, to;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		V color(G[now].size(), -1);
		ll to, idx;
		rep(i, G[now].size()) {
			to = G[now][i].first;
			idx = G[now][i].second;
			color[i] = c[idx];
		}
		ll cidx = 1;
		rep(i, G[now].size()) {
			to = G[now][i].first;
			idx = G[now][i].second;
			if (c[idx] == -1){
				while(1){
					auto itr = find(ALL(color), cidx);
					if (itr == color.end()){
						c[idx] = color[i] = cidx;
						q.push(to);
						break;
					}
					cidx++;
				}
			}
		}
	}
}

void solve_abc_d() {
    ll n;
    cin >> n;

	G = vector<vector<P>>(n + 1);
	e = vector<P>(n-1);
	c = V(n-1, -1);

	ll a, b;
	rep(i, n - 1) {
		cin >> a >> b;
		G[a].push_back(make_pair(b, i));
		G[b].push_back(make_pair(a, i));
		e[i] = make_pair(a, b);
	}

	bfs(1);

	ll k = 0;
	rep(i, n - 1) {
		k = max(k, c[i]);
	}
	cout << k << "\n";
	rep(i, n - 1){
		cout << c[i] << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_d();

	return 0;
}
