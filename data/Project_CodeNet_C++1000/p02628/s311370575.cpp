#include <algorithm>
#include <iostream>
#include <vector>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int n, k;
int main() {
	cin >> n >> k;
	vector<int> p(n);
	rep(i, 0, n) cin >> p[i];

	sort(ALL(p));
	int ans = 0;
	rep(i, 0, k) ans += p[i];
	cout << ans << endl;
    return 0;
}
