

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 998244353;

/*
    0
  1   2


*/

long long mod_pow(long long x, long long n) {
	if (n==0) return 1;
	long long res = mod_pow(x * x % MOD, n/2);
	if (n&1) res = res * x % MOD;
	return res;
}

vector<int> v;
ll c[100005];

int main(void) {
    int n, mx = -1;
    cin >> n;
    rep(i, 0, n) {
        int x;
        scanf("%d", &x);
        v.pb(x);
        mx = max(mx, x);
    }
    if (v[0]!=0) {
        puts("0");
        return 0;
    }

    rep(i, 0, n) c[v[i]]++;

    if (c[0]!=1) {
        puts("0");
        return 0;
    }
    ll ans = 1;
    rep(i, 1, mx+1) {
        ans *= mod_pow(c[i-1], c[i]);
        ans %= MOD;
    }

    cout << ans % MOD << endl;

	return 0;
}
