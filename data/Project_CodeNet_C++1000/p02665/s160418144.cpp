#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;

	vector<ll> A(n+1);
	for(int i = 0; i < n+1; ++i)
	{
		cin >> A[i];
	}

	// 深さごとの頂点数の上限
	vector<ll> MX(n+1);
	MX = A;
	for(int i = n-1; i >= 0; --i)
	{
		MX[i] += MX[i+1];
	}

	// 根っこから順に比較
	ll ans = 0, v = 1;
	for(int i = 0; i < n+1; ++i)
	{
		if (i != 0)
			v = min(v*2, MX[i]);
		ans += v;
		v -= A[i];
		// 葉の数を引いてvがマイナスになったらはじく
		if (v < 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;

	// for(int i = 0; i < n+1; ++i)
	// {
	// 	if (i)
	// 		cout << " ";
	// 	cout << MX[i];
	// }
	// cout << endl;
}

