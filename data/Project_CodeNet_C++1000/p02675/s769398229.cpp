#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	
	cin >> n;
	int tmp = n % 10;
	if (tmp == 3) cout << "bon\n";
	else if (tmp == 0 || tmp == 1 || tmp == 6 || tmp == 8) cout << "pon\n";
	else cout << "hon\n";
	
	return 0;
}