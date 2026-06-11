#include<bits/stdc++.h>
using namespace std;

int x, y, ans;
int a[210];

int main()
{
	a[1] = 300000, a[2] = 200000, a[3] = 100000;
	cin >> x >> y;
	ans = a[x] + a[y];
	if(x == 1 && y == 1) ans += 400000;
	cout << ans << endl;
	return 0;
}