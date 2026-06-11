#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N, X[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		sum += X[i];
	}

	ll ans = 0, P = sum / N;
	for (int i = 0; i < N; i++)
		ans += (ll) (X[i] * X[i]);
	ans -= (ll) 2 * P * sum;
	ans += (ll) N * P * P;

	if (sum % N == 0)
	{
		cout << ans;
		return 0;
	}

	ll ans2 = ans + (ll) 2 * P * sum - (ll) N * P * P;
	P++;
	ans2 = ans2 - (ll) 2 * P * sum + (ll) N * P * P;
	cout << min(ans, ans2);
}