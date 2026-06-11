#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

int main()
{
	int n;
	cin >> n;
	vector<int> now(n);
	now[0]=3;
	ll ans = 1;
	rep(i,n)
	{
		int foo;
		cin >> foo;
		ans *= now[foo];
		now[foo]--;
		now[foo+1]++;
		ans %= (int)1e9+7;
	}
	cout<<ans<<endl;
	return 0;
}