#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (min(a, b) < 1 || max(a, b) > 9) cout << -1;
	else cout << a * b;
	return 0;
}
