#include <iostream>
#include <vector>
#include <math.h>
#include<string>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	string str;
	cin >> str;

	vector<int> a(n, 0);

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'W')
		{
			a[i] = 1;
		}
	}
	int i = 0, j = n - 1;
	while (i < n)
	{
		if (a[i] == 1)
		{
			while (j > i)
			{
				if (a[j] == 0)
				{
					swap(a[i], a[j]);
					ans++;
					break;
				}
				j--;
			}
		}
		i++;
	}

	cout << ans << endl;

	return 0;
}