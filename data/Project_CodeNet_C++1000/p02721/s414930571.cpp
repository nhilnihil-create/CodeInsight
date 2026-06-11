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

int A[200001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, K, C;
	cin >> N >> K >> C;
	string S;
	cin >> S;

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
			if (A[i] == kari++) co(i + 1);
			i += C;
		}
	}

	Would you please return 0;
}