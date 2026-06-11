#include <iostream>
#include <vector>
using namespace std;
const int MAX = 3000;
template<class T> bool chmax(T &a, const T b) {if (a<b) {a=b; return true;} return false;}

int main() {
	int N, T;
	cin >> N >> T;
	int A[MAX], B[MAX];
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	int dp_L[MAX+2][MAX+2] = {}, dp_R[MAX+2][MAX+2] = {};
	for (int i = 1; i <= N; i++) {
		int a = A[i-1], b = B[i-1];
		for (int j = 1; j <= T; j++) {
			dp_L[i][j] = dp_L[i-1][j];
			if (j - a >= 0) chmax(dp_L[i][j], dp_L[i-1][j-a] + b);
		}
	}
	for (int i = N; i >= 1; i--) {
		int a = A[i-1], b = B[i-1];
		for (int j = 1; j <= T; j++) {
			dp_R[i][j] = dp_R[i+1][j];
			if (j - a >= 0) chmax(dp_R[i][j], dp_R[i+1][j-a] + b);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int b = B[i-1];
		for (int j = 0; j < T; j++) {
			int now = b + dp_L[i-1][j] + dp_R[i+1][T-1-j];
			ans = max(ans, now);
		}
	}
	cout << ans << endl;
	return 0;
}