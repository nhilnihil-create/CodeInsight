#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
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

const int cm = 1 << 18;
char cn[cm], * ci = cn, ct;
const int dm = 1 << 16;
char dn[dm], * di = dn;
inline int getint() {
	int A = 0;
	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}
inline void putint(int X) {
	if (X == 0) {
		*di++ = '0';
		*di++ = '\n';
		return;
	}
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	fread(cn, 1, cm, stdin);
	int K = getint(), Q = getint();
	int D[5000];
	rep(i, K) D[i] = getint();

	rep(i, Q) {
		int N = getint(), X = getint(), M = getint();
		N--;
		X %= M;

		int N2 = N / K;
		N %= K;

		ll kosuu = 0, kosuu2 = 0;
		ll kazu = 0, kazu2 = 0;
		rep(i, N) {
			int kari = D[i] - int(double(D[i]) / M) * M;
			if (kari) {
				kosuu++;
				kazu += kari;
			}
		}
		for (int i = N; i < K; i++) {
			int kari = D[i] - int(double(D[i]) / M) * M;
			if (kari) {
				kosuu2++;
				kazu2 += kari;
			}
		}
		kosuu *= N2 + 1;
		kazu *= N2 + 1;
		kosuu2 *= N2;
		kazu2 *= N2;
		kosuu += kosuu2;
		kazu += kazu2 + X;

		kosuu -= kazu / M;

		putint(kosuu);
	}

	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}