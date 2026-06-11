#include <iostream>
#include <cstdio>

#define ll long long

using namespace std;

ll a, b, res = 0;

int main()
{
	cin >> a >> b;
	if ((a + b) % 2 != 0) cout << "IMPOSSIBLE";
	else
	{
		res = (a + b) / 2;
		cout << res;
	}

	return 0;
}