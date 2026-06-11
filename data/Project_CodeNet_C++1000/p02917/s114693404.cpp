#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;
	int ans = 0;
	vector<int> A(N,0);
	vector<int> B(N-1,0);
	for (int i = 0; i < N-1; i++) {
		cin >> B[i];
	}

	A[0] = B[0];
	A[1] = B[0];

	for (int i = 1; i < N-1; i++) {
		if (A[i] > B[i]) {
			A[i] = B[i];
		}
		A[i+1] = B[i];
	}

	for (int i = 0; i < N; i++) {
		ans += A[i];
	}

	cout << ans << endl;


	return 0;
}
