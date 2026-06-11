#include <iostream>
#include <set>

using namespace std;


long long int MOD = 1000000007;

int N;
int A[100005];
multiset<int> S;

long long int dp[100005];

int main(void) {

	cin >> N;

	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i <= 2; i++) { S.insert(0); }

	for (int i = 1; i <= N; i++) {
		long long int num = S.count(A[i]);
		if (num == 0) { cout << 0 << endl; return 0; }
		dp[i] = (dp[i - 1] * num) % MOD;
		auto it = S.find(A[i]);
		S.erase(it);
		S.insert(A[i] + 1);
	}
	cout << dp[N] << endl;
	return 0;
}