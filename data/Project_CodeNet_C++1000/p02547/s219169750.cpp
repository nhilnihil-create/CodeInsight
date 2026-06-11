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
	vector<int> d1(n);
	vector<int> d2(n);
	REP(i,n){
		cin>>d1[i]>>d2[i];
	}
	REP(i,n-2){
		if(d1[i]==d2[i]&&d1[i+1]==d2[i+1]&&d1[i+2]==d2[i+2]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}