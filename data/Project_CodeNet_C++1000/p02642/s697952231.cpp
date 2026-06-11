#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int a_max = *max_element(a.begin(), a.end());
	vector<int> b(a_max + 1, 0);
	for (int i = 0; i < n; i++)
	{
		if (b[a[i]] != 0)
		{
			if (b[a[i]] == -1)
				b[a[i]] = 1;
			continue;
		}
		b[a[i]] = -1;
		for (int k = a[i] * 2; k <= a_max; k += a[i])
			b[k] = 1;
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[a[i]] == -1)
			count++;
	}
	cout << count << endl;
	return 0;
}