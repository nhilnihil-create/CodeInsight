#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	int count = 0;
	int now, prev, next;
	for (int i = 1; i <= n - 2; i++)
	{
		now = v[i];
		next = v[i + 1];
		prev = v[i - 1];

		if ((now > next && now < prev) || (now > prev && now < next))
			count++;
	}
	cout << count << endl;
}

