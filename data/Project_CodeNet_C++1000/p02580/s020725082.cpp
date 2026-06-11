#include <bits/stdc++.h>

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
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

void solve_abc_e() {
	ll n, m;
	ll h, w;
	ll l_ans = 0;

	cin >> h >> w >> m;

	multiset<P> target;
	vector<P> hi(h, make_pair(0, 0)), wi(w, make_pair(0, 0));

	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		a--;
		b--;
		target.emplace(make_pair(a, b));
		hi[a] = make_pair(hi[a].first + 1, a);
		wi[b] = make_pair(wi[b].first + 1, b);
	}

	sort(RALL(hi));
	sort(RALL(wi));

	V ht, wt;
	rep(i, hi.size()) {
		if (hi[i].first == hi[0].first) {
			ht.push_back(hi[i].second);
		}
		else {
			break;
		}
	}

	rep(i, wi.size()) {
		if (wi[i].first == wi[0].first) {
			wt.push_back(wi[i].second);
		}
		else {
			break;
		}
	}

	l_ans = hi[0].first + wi[0].first;

	P tmp;
	rep(i, ht.size()) {
		rep(j, wt.size()) {
			tmp = make_pair(ht[i], wt[j]);
			if (target.find(tmp) == target.end()) {
				cout << l_ans << "\n";
				return;
			}
		}
	}
	l_ans--;
	cout << l_ans << "\n";
	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_e();

	return 0;
}