#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
typedef long double ld;

const int INF = 1e9 + 7;
const double TT = 3.141592653589793238462643383279;

pi a[105];

int quarter(pi a) {
	if(a.F >= 0 && a.S >= 0) return 1;
	if(a.F < 0 && a.S >= 0) return 2;
	if(a.F < 0 && a.S < 0) return 3;
	if(a.F >= 0 && a.S < 0) return 4;
}
int cross(pi a, pi b) {
	return a.F * b.S - a.S * b.F;
}

ld go(ld x, ld y) {
	return x * x + y * y;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) 
		cin >> a[i].F >> a[i].S;
	sort(a+1, a+n+1, [](pi a, pi b) {
		if(quarter(a) == quarter(b)) {
			return cross(a, b) > 0;
		} else {
			return quarter(a) < quarter(b);
		}
	});
	for(int i=1;i<=n;i++) {
		a[i].F += a[i-1].F;
		a[i].S += a[i-1].S;
	}
	ld ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) {
			ans = max(ans, go(a[j].F - a[i-1].F, a[j].S - a[i-1].S));
			ans = max(ans, go(a[n].F - a[j].F + a[i].F, a[n].S - a[j].S + a[i].S));
		}
	ans = sqrtl(ans);
	cout << fixed << setprecision(15) << ans << endl;
}



