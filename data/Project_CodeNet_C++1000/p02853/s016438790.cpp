#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> x >> y;

	int ans = max(4 - x, 0) * 100000 + max(4 - y, 0) * 100000 ;
	if(x == 1 && y == 1) ans += 400000;

	cout << ans << endl;	
}
