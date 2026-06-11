#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const ll MOD = 1000000007;

int main() {
	int N, M; cin >> N >> M;
	vector<int> S(N), T(M);
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> T[i];
	}

	vector<vector<ll>> acm(N + 1, vector<ll>(M + 1));

	ll ans = 1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			acm[i+1][j+1] = (acm[i][j+1] + acm[i+1][j] - acm[i][j]) % MOD;
			if (acm[i+1][j+1] < 0) acm[i+1][j+1] += MOD;

			if (S[i] == T[j]) {
				ll val = acm[i][j] + 1;
				if (val >= MOD) val -= MOD;
				acm[i+1][j+1] = (acm[i+1][j+1] + val) % MOD;
				ans = (ans + val) % MOD;
			}
		}
	}

	cout << ans << endl;


	return 0;
}
