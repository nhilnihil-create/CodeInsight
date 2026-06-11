#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	long long all = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		all += a[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if ((double)a[i] >= (double)all / (4 * m))
		{
			ans++;
		}
	}

	if (ans >= m)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}