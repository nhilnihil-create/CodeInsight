#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	char S[200010];
	fread(S, 1, 200010, stdin);

	int L = 0, R = 200000;
	while (L + 1 < R) {
		int M = (L + R) / 2;
		if (S[M] >= '?') L = M;
		else R = M;
	}

	int r = R / 8 * 8;
	ll* owa = (ll*)(S + R);
	for (ll* kaki = (ll*)S; kaki < owa; kaki++) {
		ll tmp = *kaki;
		tmp += 0x0303030303030303;
		tmp ^= 0x0101010101010101;
		tmp += 0x0101010101010101;
		tmp &= 0xfcfcfcfcfcfcfcfc;
		*kaki = tmp;
	}
	for (int i = r; i < R; i++) {
		if (S[i] == '?') S[i] = 'D';
	}
	fwrite(S, 1, R, stdout);

	Would you please return 0;
}