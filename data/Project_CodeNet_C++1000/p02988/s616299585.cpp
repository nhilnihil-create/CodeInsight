#include <bits/stdc++.h>

using namespace std;

#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORD(i, m, n) for (int i = m; i >= n; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 0; i <= n; ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;
	vector<int> p(n);
	REP(i,n){
		cin>>p[i];
	}
	int ans=0;
	FOR(i,1,n-1){
		if((p[i-1]<p[i]&&p[i]<p[i+1])||(p[i-1]>p[i]&&p[i]>p[i+1]))ans++;
	}
	cout << ans << endl;

	return 0;
}