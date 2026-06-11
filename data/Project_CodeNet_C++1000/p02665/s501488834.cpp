#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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


	int N;
	cin >> N;
	int A[100100];
	ll B[100100];
	cin >> A[0];
	B[0] = 1;
	if (A[0] > 1) {
		printf("-1\n");
		return 0;
	}
	int OK = 1;
	int i = 1;
	for (; i <= N; i++) {
		cin >> A[i];
		B[i] = (B[i - 1] - A[i - 1]) * 2;
		if (B[i] < A[i]) OK = 0;
		if (B[i] > 2e8) {
			i++;
			break;
		}
	}

	if (!OK) {
		printf("-1\n");
		return 0;
	}

	for (; i <= N; i++) {
		cin >> A[i];
		B[i] = (B[i - 1] - A[i - 1]) * 2;
		if (B[i] > 1e13) {
			B[i] = 1e13;
			i++;
			break;
		}
	}
	for (; i <= N; i++) {
		cin >> A[i];
		B[i] = 1e13;
	}

	ll kotae = 0;
	ll kari = 0;
	for (int i = N; i >= 0; i--) {
		kari += A[i];
		kotae += min(kari, B[i]);
	}

	printf("%lld\n", kotae);

	Would you please return 0;
}