#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll,ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

constexpr ll mod = 1e9 + 7;

struct UnionFind {
public:
	vector <ll> par; // 
	vector <ll> siz; // 

	UnionFind() {}

	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}

	ll root(ll x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}

	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	bool issame(ll x, ll y) {
		return root(x) == root(y);
	}

	ll size(ll x) {
		return siz[root(x)];
	}
};

int main() {
	int h, w;
    cin >> h >> w;
    vector<string> vs(h);
    rep(i, h) {
        cin >> vs[i];
    }
	vector<vector<ll>> dp(h, vector<ll>(w, 1e15));
	if (vs[0][0] == '#') dp[0][0] = 1;
	else dp[0][0] = 0;	

	P shifts[] = { {1,0},{0,1}};
	rep(i, h) {
		rep(j, w) {
			for (auto s : shifts) {
				auto nx = j + s.first;
				auto ny = i + s.second;
				if (nx >= 0 && nx < w) {
					if (ny >= 0 && ny < h) {
						if (vs[i][j] == '.' && vs[ny][nx] == '#') {
							chmin(dp[ny][nx], dp[i][j] + 1);
						}
						else{
							chmin(dp[ny][nx], dp[i][j]);
						}
					}
				}
			}
		}
	}
	cout << dp[h - 1][w - 1] << endl;
	return 0;
}
