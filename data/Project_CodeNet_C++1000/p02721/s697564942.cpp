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

const int MAX = 200010;
class shuturyoku_unko {
public:
	char C[MAX * 7 + 10];
	int K[MAX + 10];
	constexpr shuturyoku_unko() : C(), K() {
		auto di = C + 1;
		C[0] = '0';
		K[0] = 0;
		K[1] = 1;
		rep1(i, MAX) {
			int X = i;
			int keta = 0;
			char c[10] = {};
			while (X) {
				*(c + keta) = '0' + X % 10;
				X /= 10;
				keta++;
			}
			for (int j = keta - 1; j >= 0; j--)* di++ = (*(c + j));
			*di++ = '\n';
			K[i + 1] = K[i] + keta + 1;
		}
	}
} f;
const int dm = 1 << 21;
char dn[dm], * di = dn;
inline void putint(int X) {
	for (int i = f.K[X]; i < f.K[X + 1]; i++)* di++ = f.C[i];
}

int A[200001];
int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N, K, C;
	scanf("%d %d %d ", &N, &K, &C);

	if (N == K) {
		fwrite(f.C + 1, 1, f.K[N + 1] - f.K[1], stdout);
		return 0;
	}

	char S[200010];
	fread(S, 1, N, stdin);

	int kari = K;
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == 'o') {
			A[i] = kari--;
			i -= C;
		}
	}
	kari = 1;
	rep(i, N) {
		if (S[i] == 'o') {
			if (A[i] == kari++) putint(i + 1);
			i += C;
		}
	}
	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}