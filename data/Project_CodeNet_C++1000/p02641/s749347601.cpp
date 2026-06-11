#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int x, n;
	cin >> x >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int k = 0;
	while (true)
	{
		int min_val = min(x - k, x + k);
		int max_val = max(x - k, x + k);
		if (find(p.begin(), p.end(), min_val) == p.end())
		{
			cout << min_val << endl;
			break;
		}
		if (find(p.begin(), p.end(), max_val) == p.end())
		{
			cout << max_val << endl;
			break;
		}
		k++;
	}
	return 0;
}