#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b >> c;
	
	int t = b * c;
	if (t >= a) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
