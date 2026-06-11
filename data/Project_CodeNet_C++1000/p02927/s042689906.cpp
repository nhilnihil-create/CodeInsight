#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
using namespace std;

int main()
{
	int m, d; cin >> m >> d;
	int ans = 0;
	rep1(i, m)rep1(j, d)
	{
		int d1 = j % 10;
		int d10 = j / 10;
		if (d1>=2 && d10 >=2 && i == d1 * d10)ans++;
	}
	co(ans);
	return 0;
}