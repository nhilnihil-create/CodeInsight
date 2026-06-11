#include "bits/stdc++.h"
using namespace std;
const int INF = 1 << 30;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		A[x - 1]++;
	}
	sort(A.begin(), A.end());
	vector<int>S(N + 1);
	for (int i = 0; i < N; ++i) {
		S[i + 1] = S[i] + A[i];
	}
	for (int i = 1; i <= N; ++i) {
		int l = 0;//ok
		int r = N / i + 1;//ng
		while (l +1 <r) {
			int c = (l+r) / 2;
			bool b = false;
			int j = lower_bound(A.begin(),A.end(),c)-A.begin();
			int sum = c * (N - j) + S[j];
			if (sum >= c*i) {
				b = true;
			}
			if (b) {
				l = c;
			}
			else {
				r = c;
			}
		}
		cout << l << endl;
	}
	return 0;
}