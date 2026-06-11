#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;

using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
/*
template<typename... Args>
void print(Args... args) {
	#ifdef LOCAL
	((std::cout << args << " "), ...);
	cout << endl;
	#endif
}
 */
//endregion

/* Notes:
 * Farah </3
 */
const int MAXN = 2e3 + 6;

ll fact[MAXN];

long long modPow(ll b , long long pow){
	long long ans = 1;
	long long p = b;
	while(pow){
		if(pow & 1)
			ans = (ans * p) % MOD;
		p = (p * p) % MOD;
		pow >>= 1;
	}
	return ans;
}

void pre(){
	fact[0] = fact[1] = 1;

	for(ll i = 2; i <= 2005; i++){
		fact[i] = (i * fact[i - 1]) % MOD;
	}
}

ll ncr(int n, int r){
	ll x =  (fact[n] * modPow( fact[r], MOD - 2)) % MOD;
	x = (x * modPow( fact[n - r], MOD - 2)) % MOD;

	return x;
}

char g[MAXN][MAXN];
int comprow[MAXN][MAXN];
int compcol[MAXN][MAXN];

int rowval[MAXN][MAXN];
int colval[MAXN][MAXN];

int h, w;

void prow(int r){
	int cur = 1;
	for(int i = 0; i < w; i++){
		if(g[r][i] == '#') cur++;
		else {
			comprow[r][i] = cur;
			rowval[r][cur]++;
		}
	}
}

void pcol(int c){
	int cur = 1;
	for(int i = 0; i < h; i++){
		if(g[i][c] == '#') cur++;
		else {
			compcol[i][c] = cur;
			colval[c][cur]++;
		}
	}
}

int main() {
	#ifdef LOCAL

	setIn("in.txt");
	setOut("out.txt");
	#endif

	cin >> h >> w;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> g[i][j];
		}
	}

	for(int i = 0; i < h; i++){
		prow(i);
	}
	for(int i = 0; i < w; i++){
		pcol(i);
	}

	int ans = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			ans = max(ans, rowval[i][comprow[i][j]] + colval[j][compcol[i][j]] - 1);
		}
	}

	cout << ans << endl;
}
