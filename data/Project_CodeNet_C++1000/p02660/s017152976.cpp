#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;

ll N, ans;

int main()
{
	cin >> N;
	for (ll i = 2, M = N; i * i <= M; i++)
	{
		ll z = i;
		while (N % z == 0)
			ans++, N /= z, z *= i;
		while (N % i == 0)
			N /= i;
	}

	cout << ans + (N != 1) << "\n";
}
