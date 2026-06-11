#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int A[200010];
int main()
{
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int ans = mod;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			ans = min(ans, K - (K - (A[N - 1] - A[i])));
			ans = min(ans, K - (A[i + 1] - A[i]));
		}
		else if (i == N - 1) {
			ans = min(ans, K - (A[i] - A[i - 1]));
			ans = min(ans, K - (K - (A[N - 1] - A[0])));
		}
		else {
			ans = min(ans, K - (A[i] - A[i - 1]));
			ans = min(ans, K - (A[i + 1] - A[i]));
		}
	}
	cout << ans << endl;
}