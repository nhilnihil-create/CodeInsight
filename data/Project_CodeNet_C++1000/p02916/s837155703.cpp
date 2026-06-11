#include<bits/stdc++.h>

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
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n-1);
	REP(i,n){
		cin>>a[i];
		--a[i];
	}
	REP(i,n){
		cin>>b[i];
	}
	REP(i,n){
		cin>>c[i];
	}
	int sum=0;
	REP(i,n){
		sum+=b[a[i]];
		if(i>0&&a[i]==a[i-1]+1)sum+=c[a[i-1]];
	}
	cout << sum << endl;

	return 0;
}
