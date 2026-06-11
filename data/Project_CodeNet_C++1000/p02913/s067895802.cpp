#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 998244353, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;

/*一致文字数を計算する(計算量|S|)*/
ll* Z_algorithm(string S){
	ll i = 1, j = 0;
	ll* R;
	R = (ll*)malloc(sizeof(string)*S.length());
	R[0] = S.size();
	while (i < S.size()) {
		while (i+j < S.size() && S[j] == S[i+j]) ++j;
		R[i] = j;
		if (j == 0) { ++i; continue;}
		ll k = 1;
		while (i+k < S.size() && k+R[k] < j) R[i+k] = R[k], ++k;
		i += k; j -= k;
	}
	return R;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	string S;
	ll _max = 0;
	cin >> N >> S;
	rep(i, N){
		ll* R = Z_algorithm(S.substr(i));
		rep(j, N-i-1){
			if(R[j+1] <= j+1) _max = max(_max, R[j+1]);
		}
		free(R);
	}
	cout << _max;
}