#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

bool fn_is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

bool isOK(int index, int key, vector<ll>& a) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key, vector<ll>& a) {
    int ng = -1;
    int ok = a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

struct UnionFind {
    vector<int> r;

    UnionFind(int N) {
        r = vector<int>(N, -1);
    }

    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

ll calc(ll a, ll b, ll p) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        ll d = calc(a, b/2, p);
        return (d * d) % p;
    } else {
        return (a * calc(a, b-1, p)) % p;
    }
}
     
int main()
{
    int n, m; cin >> n >> m;
    priority_queue<ll> q;
    rep(i,n) {
        ll a; cin >> a;
        q.push(a);
    }

    ll tmp;
    rep(i,m) {
        tmp = q.top();
        q.pop();
        q.push(tmp/2);
    }
    ll ans = 0;

    while (!q.empty()) {
        tmp = q.top();
        q.pop();
        ans += tmp;
    }
    cout << ans << endl;
}
