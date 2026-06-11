#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;

	// C[i] := i番目の箱に入っている玉の数
	// B[i] := C[i] + C[i*2] + C[i*3] + ...
	vector<ll> A(n + 1), B(n + 1, 0), C(n + 1, 0);
	for (ll i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	// iが大きい方から見ていく
	for (ll i = n; i >= 1; i--)
	{
		if (B[i] % 2 == A[i]) { continue; }

		// 偶奇が異なる場合に玉を入れる
		C[i] ++;

		// i の約数にも玉を入れる
		for (ll j = 1; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				B[j] ++;
				if ( j * j != i ) B[i/j] ++;
			}
		}
	}

	ll cnt = 0;
	for (ll i = 1; i <= n; i++)
	{
		if (B[i] % 2 != A[i]) { cnt = -1; break; }
		if (C[i] > 0) cnt++;
	}

	cout << cnt << endl;
	if (cnt > 0)
	{
		bool f = true;
		for (ll i = 1; i <= n; i++)
		{
			if ( C[i] == 0 ) continue;
			if ( f )
			{
				cout << i;
				f = false;
			}
			else
				cout << " " << i;
		}
		cout << endl;
	}


	return 0;
}
