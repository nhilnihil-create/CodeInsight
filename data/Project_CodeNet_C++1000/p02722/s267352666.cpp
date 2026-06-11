#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

set<ll> divisor(ll n) {
    set<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.insert(i);
            if(i * i != n)
                ret.insert(n / i);
        }
    }
    return ret;
}

ll simulate(ll N, ll num) {
    while(N >= num) {
        if(N % num == 0) {
            N /= num;
        } else {
            N %= num;
        }
    }
    return N;
}

int main() {
    ll N;
    cin >> N;
    auto div = divisor(N);
    auto div2 = divisor(N - 1);
    set<ll> res;
    for(auto d : div) {
        if(d == 1)
            continue;
        if(simulate(N, d) == 1)
            res.insert(d);
    }
    for(auto d : div2) {
        if(d == 1)
            continue;
        if(simulate(N, d) == 1)
            res.insert(d);
    }

    cout << res.size() << endl;
    return 0;
}