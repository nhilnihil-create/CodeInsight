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
	string S;
	cin >> S;

	int ans =1;
	int f = S[0];
	for (int i = 0; i < n; ++i)
	{
		if (S[i] != f)
			++ans;
		f = S[i];
	}
	cout << ans << endl;
}

