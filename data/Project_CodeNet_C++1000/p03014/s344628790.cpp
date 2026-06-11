#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
vector<int> row[N], col[N];
string a[N];
int h, w;
int gsearch(vector<int> &v, int k, int n)
{
	int low = 0, high = (int)v.size() - 1, ans = n;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] > k)
		{
			ans = v[mid] - 1;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}
int ssearch(vector<int> &v, int k, int n)
{
	int ans = n;
	int low = 0, high = (int)v.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v[mid] < k)
		{
			ans = v[mid] + 1;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		cin >> a[i];
		for (int j = 0; j < w; ++j)
		{
			if (a[i][j] == '#')
			{
				col[j].push_back(i);
				row[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (a[i][j] == '#')
				continue;
			int l = ssearch(row[i], j, 0), r = gsearch(row[i], j, w - 1), u = ssearch(col[j], i, 0), d = gsearch(col[j], i, h - 1);
			int c = r - l + 1 + d - u;
			//cout << i << ' ' << j << ' ' << l  << ' ' << r << ' ' << u << ' ' << d << '\n';
			ans = max(ans, c);

		}
	}
	cout << ans << '\n';
	return 0;
}