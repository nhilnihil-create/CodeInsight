#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE

	// For getting input from input.txt file
	freopen("input1.txt", "r", stdin);

	// Printing the Output to output.txt file
	freopen("output1.txt", "w", stdout);

#endif
	/*Always stress test, for n=0, n=1, n=10^9,what if n<k and so on */
	/* Please remember 10^7 se bada array is not possible */
	/* Always use pen and paper, don't just look at the screen*/
	/* Try finding a pattern on pen and paper until y0u get it*/
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		ll cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if (a[i] % 2 && (i + 1) % 2)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}

