#include "bits/stdc++.h"

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<set<int>> A(N);
	for (int n = 0;n<M;++n) {
		int s,c;
		cin >> s >> c;
		A[s - 1].insert(c);
	}
	
	int ans = 1;
	if (0 == A[0].size()) {
		if (1 == N) {
			ans = 0;
		}
	}
	else if (1 == A[0].size()) {
		ans = *A[0].begin();
		if (0 == ans&&N != 1) {
			cout << "-1" << endl;
			return 0;
		}
	}
	else {
		cout << "-1" << endl;
		return 0;
	}



	for (int n = 1;n<N;++n) {
		int num = 0;
		if (A[n].size()>1) {
			cout <<"-1"<<endl;
			return 0;
		}
		if (A[n].size() == 1) {
			num = *A[n].begin();
		}
		if (num == 0 && 0 == n) {
			if (1 != N) {
				num = 1;
			}
		}
		ans = 10 * ans + num;
	}
	cout << ans << endl;
	return 0;
}
