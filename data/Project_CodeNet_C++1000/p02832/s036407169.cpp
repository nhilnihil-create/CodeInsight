#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n, -1);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		x --;
		if (x == 0)
			a[x] = 0;
		else
		{
			if (a[x - 1] == x - 1)
				a[x] = x;
		}
	}
	int mx = *max_element(a.begin(), a.end());
	if (mx == -1)
		cout << -1 << '\n';
	else
		cout << n - mx - 1 << '\n';
	return 0;
}