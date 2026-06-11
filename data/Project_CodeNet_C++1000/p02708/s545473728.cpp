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

ll sum[200010];
int main()
{
	int N, K;
	cin >> N >> K;
	ll ans = 0;
	for (int i = 0; i < N + 1; i++) {
		sum[i + 1] = sum[i] + i + 1;
	}
	for (int i = K; i <= N + 1; i++) {
		ll num1 = sum[i - 1] - sum[0];
		ll num2 = sum[N] - sum[N - i];
		ans = (ans + num2 - num1 + 1) % mod;
	}
	cout << ans << endl;
}