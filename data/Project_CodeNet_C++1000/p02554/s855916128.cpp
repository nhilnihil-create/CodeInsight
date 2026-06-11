#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
const long long MOD = 1000000007;

//* calculate x^n mod something in O(log n) -- recursive version
ll mod_pow(ll x, ll n, ll mod){
    if(n == 0) return 1;
    ll res = mod_pow(x*x % mod, n/2, mod);
    if(n & 1) res = res * x % mod;
    return res;
}

void solve(long long N){
    ll ans = 0;
    ll tmp = mod_pow(10, N, MOD);
    ans = mod_pow(10, N, MOD) + mod_pow(8, N, MOD) - 2* mod_pow(9, N, MOD);
    ans = ans % MOD;
    if(ans < 0 ) ans += MOD;
    cout<<ans<<endl;

}
int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
