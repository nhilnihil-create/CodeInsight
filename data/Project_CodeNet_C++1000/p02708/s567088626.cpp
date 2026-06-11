#include <queue>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <time.h>
#include <functional>

//#include "All.h"

using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    REP(i, b) tmp *= a;
    return tmp;
}

ll N, K;
ll ans = 0;

int main() {
    cin >> N >> K;
    //for (ll k = K - 1; k <= N; k++) {
    //    ans += -k * k + (N - 1) * k + N + 1;
    //    ans %= ll(1e9) + 7;
    //}
    ll n = N - (K - 1);
    ans += -n * (n + 1) * (2 * n + 1) / 6;
    ll mod = ll(1e9) + 7;
    ans %= mod;
    ans += (N - 2 * K + 1) * n * (n + 1) / 2;
    ans %= mod;
    ans += (n + 1) * (-(K - 1) * (K - 1) + (N - 1) * (K - 1) + N + 1);
    ans %= mod;
    cout << ans << endl;
}