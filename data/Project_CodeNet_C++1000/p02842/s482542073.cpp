#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	int withouttax;
	cin >> n;
	withouttax = n;
	while (withouttax * 27 / 25 >= n)
	{
		if (withouttax * 27 / 25 == n)
		{
			cout << withouttax << '\n';
			return (0);
		}
		withouttax--;
	}
	cout << ":(" << '\n';
	return (0);
}
