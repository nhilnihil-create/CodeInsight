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
#define Would
#define you
#define please

//みんなどんだけ頭いいの

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = 0;
	char c;
	while ((c = getchar_unlocked()) >= '0') N = N * 10 + c - '0';

	int L = 0;
	ll kotae = 1;
	ll mod = 1e9 + 7;
	rep1(i, N) kotae = kotae * i % mod;
	rep(i, N + N) {
		char c = getchar_unlocked();
		if (i & 1) {
			if (c == 'W') {
				L++;
			}
			else {
				kotae = kotae * L % mod;
				L--;
			}
		}
		else {
			if (c == 'B') {
				L++;
			}
			else {
				kotae = kotae * L % mod;
				L--;
			}
		}
	}

	if (L == 0) printf("%ld", kotae);
	else printf("0");

	Would you please return 0;
}