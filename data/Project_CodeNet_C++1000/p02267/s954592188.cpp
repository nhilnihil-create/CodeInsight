#include<iostream>
using namespace std;

int main()
{
	int s[10000], t, n, q, count = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> t;
		for (int j = 0; j < n; j++)
			if (s[j] == t)
			{
				count++;
				break;
			}
	}

	cout << count << endl;

	return 0;
}
