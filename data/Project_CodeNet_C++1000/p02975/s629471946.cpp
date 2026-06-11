#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>

using namespace std;
typedef long long  ll;

const ll mod = 1000000007;

int main()
{
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (N % 3 == 0)
	{
		if (a[0] == 0 && a[N / 3 - 1] == 0 && a[N / 3] == a[N - 1])
		{
			cout << "Yes" << endl;
			return 0;
		}
		else if (a[0] == a[N / 3 - 1] && a[N / 3] == a[2 * N / 3 - 1] && a[2 * N / 3] == a[N - 1] && (a[0]^a[N / 3]^a[2 * N / 3]) == 0 && a[0] != a[N / 3] && a[0] != a[2 * N / 3] && a[N / 3] != a[2 * N / 3])
		{
			cout << "Yes" << endl;
			return 0;
		}
		else
		{
			cout << "No" << endl;
			return 0;
		}
	}
	else
	{
		if (a[0] == 0 && a[N - 1] == 0)
		{
			cout << "Yes" << endl;
			return 0;
		}
		else
		{
			cout << "No" << endl;
			return 0;
		}
	}
	return 0;
}