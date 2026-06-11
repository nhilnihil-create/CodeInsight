#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int all_xored = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		all_xored ^= a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			cout << " ";
		cout << (all_xored ^ a[i]);
	}
	cout << endl;
	return 0;
}