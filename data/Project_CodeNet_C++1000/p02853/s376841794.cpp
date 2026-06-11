#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define ALL(a) (a).begin(),(a).end()
#define MOD 1e9+7
typedef long long ll;
using namespace std;

int x,y;

int main()
{
	cin >> x >> y;
	int ans = 0;
	if (x <= 3) ans += 100000 * (4 - x);
	if (y <= 3) ans += 100000 * (4 - y);
	if (x == 1 && y == 1)ans += 400000;
	co(ans);
	return 0;
}

