#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int n, k;

bool check(vector<int>& w, int m)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += w[i];
		while (sum > m)
		{
			sum = w[i];
			++cnt;
			if (cnt == k)
			{
				return(false);
			}
		}
	}
	return(true);
}

void solve()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	vector<int> w(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> w[i];
	}
	int l = 0;
	int r = INT_MAX;
	while (l < r)
	{
		int mid = (l + r) / 2;		
		if (check(w, mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << l << endl;
}

int main()
{
	solve();
	return(0);
}