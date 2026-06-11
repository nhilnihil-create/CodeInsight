#pragma GCC optimize ("O2")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
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

//みなさん天才的ですよね

int KH[300001], KW[300001];
int h[300001], w[300001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int H, W, M;
	cin >> H >> W >> M;

	rep(i, M) {
		cin >> h[i] >> w[i];
		KH[h[i]]++;
		KW[w[i]]++;
	}

	int saidaih = -1, hh = 0;
	rep1(i, H) {
		if (saidaih < KH[i]) {
			saidaih = KH[i];
			hh = 1;
		}
		else if (saidaih == KH[i]) hh++;
	}
	int saidaiw = -1, ww = 0;
	rep1(i, W) {
		if (saidaiw < KW[i]) {
			saidaiw = KW[i];
			ww = 1;
		}
		else if (saidaiw == KW[i]) ww++;
	}

	ll are = ll(hh) * ww;

	int kazu = 0;
	rep(i, M) {
		kazu += (KH[h[i]] == saidaih && KW[w[i]] == saidaiw);
	}

	if (kazu == are) co(saidaih + saidaiw - 1);
	else co(saidaih + saidaiw);

	Would you please return 0;
}