#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{ return firstElof.second < secondElof.second; }
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, W, L; string S;
ll MOD = 1000000007; ll ans = 1; ll INF = 9999999999999;
vl flag, color; vll path;
//***********//

int main() {
	cin >> N >> K;
	if (K > N* (N - 1) / 2 - (N - 1)) {
		cout << -1;
		exit(0);
	}
	else {
		vpll A;
		for (k = 2; k <= N; k++) {
			A.push_back(make_pair(1, k));
		}
		ll Q = N * (N - 1) / 2 - (N - 1) - K;
		for (k = 2; k <= N - 1; k++) {
			if (Q == 0) { break; }
			for (l = k + 1; l <= N; l++) {
				A.push_back(make_pair(k, l));
				Q--;
				if (Q == 0) { break; }
			}
			if (Q == 0) { break; }
		}
		M = A.size();
		cout << M << endl;
		for (i = 0; i < M; i++) {
			cout << A[i].first << " " << A[i].second << endl;
		}
	}
}
