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
using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    REP(i, b) tmp *= a;
    return tmp;
}

ll N;
ll ans = -1;

int main() {
    cin >> N;
    vector<ll> res, res2;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.emplace_back(i);
            if (i != N / i) res.emplace_back(N / i);
        }
    }
    for (ll i = 1; i * i <= N - 1; ++i) {
        if ((N - 1) % i == 0) {
            //res2.emplace_back(i);
            ans++;
            if (i != (N - 1) / i) {
                //res2.emplace_back((N - 1) / i);
                ans++;
            }
        }
    }
    //REP(i, res.size()) {
    //    cout << res[i] << endl;
    //}

    //とりあえず全部わって余り求める
    REP(i, res.size()) {
        ll n = N;
        if (res[i] == 1) continue;
        while (n % res[i] == 0 && n >= res[i]) {
            n /= res[i];
        }
        if (n == 1) ans++;
        else if (n % res[i] == 1) ans++;
    }
    cout << ans << endl;
}
