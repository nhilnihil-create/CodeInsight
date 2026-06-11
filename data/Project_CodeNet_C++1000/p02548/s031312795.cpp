#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int ans = 0;
	for (int a = 1; a < n; ++a)
		for (int b = n/a; b > 0; --b)
			if (n - a*b > 0)
				ans++;
	cout << ans << endl;
}
