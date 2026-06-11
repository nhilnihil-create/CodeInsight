#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	int N; cin >> N;

	vector<int> A(N,0);
	vector<int> B(N,0);
	vector<int> C(N-1,0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N-1; i++) {
		cin >> C[i];
	}

	int old = -100;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += B[A[i]-1];
		if (A[i] - old == 1) {
			ans += C[old-1];
		}
		old = A[i];
	}
	cout << ans << endl;

	return 0;
}
