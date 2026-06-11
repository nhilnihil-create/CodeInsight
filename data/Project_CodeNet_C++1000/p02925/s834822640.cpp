#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> A(N, vector <int>(N-1));
	for (int ii = 0; ii < N; ++ii){
		for (int jj = 0; jj < N-1; ++jj){
			cin >> A[ii][jj];
			A[ii][jj]--;
		}
	}

	int ans = 0;
	while (true) {
		//処理
		vector <int> skip(N, 0);
		bool OK = false;
		bool allZero = true;
		for (int ii = 0; ii < N; ++ii){
			if (A[ii].size() == 0){
				skip[ii] = 1;
			} else {
				allZero = false;
			}
			if (skip[ii] == 1){
				continue;
			}

			int teki = A[ii].front();
			if ( (A[teki].front() == ii) && (skip[teki] == 0) ){
				OK = true;
				A[ii].erase(A[ii].begin());
				A[teki].erase(A[teki].begin());
				skip[ii] = 1;
				skip[teki] = 1;
			}
		}

		if (allZero){
			break;
		}
		ans++;
		if (OK == false){
			ans = -1;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}
