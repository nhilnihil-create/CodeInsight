#include<bits/stdc++.h>
using namespace std;


int main()
{
	int x, n, p;
	cin >> x >> n;
	if (n == 0)  
	{
		cout << x << endl;	
		return 0;
	}
	set<int> P;
	for (int i = 0; i < n; ++i)
	{
		cin >> p;
		P.insert(p);
	}
	int ans = 0, min = 1e9;
	for (int i = -1001; i < 1001; ++i)
	{
		if (P.count(i))
			continue;
		if (abs(i - x) < min)
		{
			min = abs(i - x);
			ans = i;
		}
	}
	cout << ans << endl;
}

