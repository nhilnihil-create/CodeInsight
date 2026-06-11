#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> x(n);
	for(auto&& i: x)
	{
		cin >> i;
	}

	int ans = 1e9;
	for(int i = 0; i <= 100; i++)
	{
		int sum = 0;
		for(auto&& a: x)
		{
			sum += (a - i)*(a - i);
		}
		ans = min(ans, sum);
	}

	cout << ans << endl;
}
