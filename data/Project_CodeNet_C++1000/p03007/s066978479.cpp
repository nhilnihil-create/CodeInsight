#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A.begin(), A.end());
	vector<pair<int, int>> ans;
	for (int i = 1; i < N - 1; ++i) {
		if (A[i] > 0) {
			ans.emplace_back(A[0], A[i]);
			A[0] -= A[i];
		} else {
			ans.emplace_back(A[N-1], A[i]);
			A[N-1] -= A[i];
		}
	}
	ans.emplace_back(A[N-1], A[0]);
	cout<< A[N-1] - A[0] <<endl;
	for (auto p : ans) cout << p.first << " " << p.second << endl;
	return 0;
}