#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
 
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const ll INF = 1023456789;
 
#define REP(i,n)	for(int i=0;i<n;++i)
#define REPR(i,n)	for(int i=n-1;i>=0;--i)
#define FOR(i,s,n)	for(int i=s;i<n;++i)
#define FORR(i,s,n)	for(int i=n-1;i>=s;--i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define F			first
#define S			second

ll n, a[100001];
ll mi, ma[100001];
 
int main(int argc, char **argv) {
	cin >> n;
	REP(i, n+1) cin >> a[i];
	mi = ma[n] = a[n];
	FORR(i, 1, n+1) {
		mi = max((ll)1, (mi+1)/2 + a[i-1]);
		ma[i-1] = ma[i] + a[i-1];
	}
	if (mi >= 2) {
		cout << -1 << endl;
		return 0;
	}
	ma[0] = 1;
	ll res = 1;
	REP(i, n) {
		ma[i+1] = min(ma[i+1], (ma[i] - a[i]) * 2);
		if (ma[i+1] <= 0) {
			cout << -1 << endl;
			return 0;
		}
		res += ma[i+1];
	}
	cout << res << endl;
	return 0;
}
 