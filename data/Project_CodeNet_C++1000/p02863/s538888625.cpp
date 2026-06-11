#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N, T;
	cin >> N >> T;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
	}
	vector<vector<int>> dp1(N + 1, vector<int>(T, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < min(A[i], T); j++){
			dp1[i + 1][j] = dp1[i][j];
		}
		for (int j = A[i]; j < T; j++){
			dp1[i + 1][j] = max(dp1[i][j], dp1[i][j - A[i]] + B[i]);
		}
	}
	vector<vector<int>> dp2(N + 1, vector<int>(T, 0));
	for (int i = N - 1; i >= 0; i--){
		for (int j = 0; j < min(A[i], T); j++){
			dp2[i][j] = dp2[i + 1][j];
		}
		for (int j = A[i]; j < T; j++){
			dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - A[i]] + B[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < T; j++){
			ans = max(ans, dp1[i][j] + dp2[i + 1][T - 1 - j] + B[i]);
		}
	}
	cout << ans << endl;
}