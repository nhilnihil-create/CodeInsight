#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<int> b(102, 0);

	for (int i = 0; i < n; i++)
	{
		b[a[i]] = 1;
	}

	if (b[x] == 0)
	{
		cout << x << endl;
		return 0;
	}

	int f = x;
	int g = x;

	while (x)
	{
		f--;
		g++;

		if (b[f] == 0)
		{
			cout << f << endl;
			return 0;
		}

		if (b[g] == 0)
		{
			cout << g << endl;
			return 0;
		}
	}

	return 0;
}