#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

int main()
{
	faster;

	int a, b, c;
	int k, cnt = 0;
	cin >> a >> b >> c >> k;

	while (b <= a)
	{
		b *= 2;
		cnt++;
	}

	while (c <= b)
	{
		c *= 2;
		cnt++;
	}

	cout << ((cnt <= k) ? "Yes" : "No") << endl;
	return 0;
}