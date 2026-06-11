#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
constexpr int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int m = 1 << n;
	map<int, int> cnt;
	REP(i, m) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	map<int, int> now;
	{
		auto c = cnt.end();
		c--;
		int b = (*c).first;
		if (--cnt[b])cnt.erase(b);
		now[b]++;
	}
	REP(i, n) {
		map<int, int> next;
		for (auto&& a : now) {
			REP(j, a.second) {
				auto c = cnt.lower_bound(a.first);
				if (c == cnt.begin()) {
					cout << "No" << endl;
						return 0;
				}
				c--;
				int b = (*c).first;
				next[b]++;
				if (--cnt[b] == 0)cnt.erase(b);
			}
		}
		for (auto&& a : now) {
			next[a.first] += a.second;
		}
		now = next;
	}
	cout << "Yes" << endl;
}