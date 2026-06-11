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

	ll a,b,k;
	cin>>a>>b>>k;
	ll a1,b1;
	if(k>a){
		k-=a;
		a1=0;
	}
	else {
		a1=a-k;
		k=0;
	}
	if(k>b){
		b1=0;
	}
	else {
		b1=b-k;
	}
	cout << a1 << " " << b1 << endl;

	return 0;
}