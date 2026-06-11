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
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();


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

int main()
{
    int n, m; cin >> n >> m;
    map<int, int> mp;
    rep(i,n) {
        mp[i+1] = -1;
    }
    if (m == 0) {
        if (n == 1)
            cout << 0 << endl;
        if (n == 2)
            cout << 10 << endl;
        if (n == 3)
            cout << 100 << endl;
        return 0;
    }

    rep(i,m) {
        int s, c; cin >> s >> c;
        if (mp[s] == -1) {
            mp[s] = c;
        } else if (mp[s] != c) {
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i,n) {
        if (i == 0) {
            if (mp[i+1] == 0) {
                if (n == 1)
                    cout << 0 << endl;
                else
                    cout << -1 << endl;
                return 0;
            }
            if (mp[i+1] == -1) {
                cout << 1;
            } else {
                cout << mp[i+1];
            }
            continue;
        }
        if (mp[i+1] == -1) {
            cout << 0;
        } else {
            cout << mp[i+1];
        }
    }
    cout << endl;

    return 0;
}
