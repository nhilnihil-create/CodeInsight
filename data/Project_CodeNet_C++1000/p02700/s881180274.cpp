#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int th, ts, ah, as; cin >> th >> ts >> ah >> as;
	int c = 1000;
	while (c--)
	{
		ah = ah - ts;
		if (ah <= 0)
		{
			cout << "Yes" << endl;
			return 0;
		}
		th = th - as;
		if (th <= 0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	return 0;
}