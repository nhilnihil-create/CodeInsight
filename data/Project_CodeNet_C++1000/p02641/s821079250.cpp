#include<bits/stdc++.h>
using namespace std;


int main()
{
	int x, n;
	cin >> x >> n;
	vector<bool> is_in(101, false);
	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		is_in[p] = true;
	}
	int left = x, right = x;
	while (is_in[x])
	{
		left--;
		right++;
		if (!is_in[right]) x = right;
		if (!is_in[left]) x = left;
	}
	cout << x << endl;
}

