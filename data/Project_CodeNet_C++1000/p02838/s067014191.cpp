#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 100000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

#define MOD 1000000007

ll c[60];

int main () {
    ll N;
    cin >> N;
	vector<ll> a(N);
	rep(i,N) cin >> a[i];
	rep(k,60) rep(i,N)
		c[k] += (a[i] >> k) & 1;
	ll ans = 0;
	ll tmp;
	ll b = 1;
	rep (k,60) {
		tmp = c[k] * (N - c[k])%MOD;
		ans += tmp * b;
		ans %= MOD;
		b = b*2%MOD;
	}
	cout << ans << endl;
    return 0;
}