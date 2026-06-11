#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N, K, S;
	cin >> N >> K >> S;
	vector<int> ans(N);
	for (int i = 0; i < K; i++)
		ans[i] = S;
	for (int i = K; i < N; i++)
	{
		if (S == 1e9)
			ans[i] = 1;
		else
			ans[i] = S+1;
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[i];
		if (i != N-1)
			cout << " ";
	}
	cout << endl;
}

