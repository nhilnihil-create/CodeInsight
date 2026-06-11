#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a - 2*b > 0)
		cout << a - 2*b << '\n';
	else
		cout << 0 << '\n';
}
