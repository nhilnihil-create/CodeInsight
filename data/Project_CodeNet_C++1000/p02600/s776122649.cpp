#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long int li;
typedef long long ll;
typedef long double ld;

int main()
{
    int n, k = 1;
    cin >> n;
    if (n >= 1800 && n <= 1999)
		k = 1;
	else if (n >= 1600 && n <= 1799)
		k = 2;
	else if (n >= 1400 && n <= 1599)
		k = 3;
	else if (n >= 1200 && n <= 1399)
		k = 4;
	else if (n >= 1000 && n <= 1199)
		k = 5;
	else if (n >= 800 && n <= 999)
		k = 6;
	else if (n >= 600 && n <= 799)
        k = 7;
	else if (n >= 400 && n <= 599)
		k = 8;
	cout << k << "\n";
}
