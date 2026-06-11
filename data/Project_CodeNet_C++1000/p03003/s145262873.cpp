/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
ll n, m;
vector<ll> s, t;
ll memo[2200][2200];
ll rec(ll i, ll j){
    if(i == 0 && j == 0) return 1;
    if(memo[i][j] != -1) return memo[i][j];
    ll res = 0;
    if(s[i - 1] == t[j - 1]){
        if(i - 1 >= 0 && j - 1 >= 0) res += rec(i - 1, j - 1);
    }
    res %= MOD;
    if(i - 1 >= 0) res += rec(i - 1, j);
    res %= MOD;
    if(j - 1 >= 0) res += rec(i, j - 1);
    res %= MOD;
    if(i - 1 >= 0 && j - 1 >= 0) res -= rec(i - 1, j - 1);
    res %= MOD;

    //cout << i << " " << j << " " << res << endl;
    return memo[i][j] = res;
}
int main(void){
    int n, m;
    cin >> n >> m;
    s.resize(n);
    t.resize(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    rep(i,2020){
        rep(j,2020){
            memo[i][j] = -1;
        }
    }
    ll ans = rec(n, m);
    while(ans < 0) ans += MOD;
    cout << ans % MOD << endl;
}