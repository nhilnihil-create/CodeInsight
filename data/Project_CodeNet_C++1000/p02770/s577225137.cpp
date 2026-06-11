#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
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
	cin.tie(0);
	ios::sync_with_stdio(false);


	int K, Q;
	cin >> K >> Q;
	int D[5000];
	rep(i, K) cin >> D[i];

	rep(i, Q) {
		ll N, X, M;
		cin >> N >> X >> M;
		N--;
		X %= M;

		ll N2 = N / K;
		N %= K;

		ll kosuu = 0;
		ll kazu = 0;
		rep(i, K) {
			if (D[i] % M) {
				kosuu++;
				kazu += D[i] % M;
			}
		}
		kazu *= N2;
		kosuu *= N2;
		kosuu -= kazu / M;
		ll amari = kazu % M;

		X += amari;
		rep(i, N) {
			if (D[i] % M) {
				kosuu++;
				X += D[i] % M;
			}
		}
		kosuu -= X / M;

		co(kosuu);
	}



	Would you please return 0;
}