#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A, B;

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> A >> B;

	int tot = 1, ans = 0;

	while (tot < B)
	{
		tot = tot - 1 + A;
		ans++;
	}

	cout << ans;
}