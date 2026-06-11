#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)


















int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), c(n + 1);
    REP(i, n){
        cin >> a[i];
        c[a[i]]++;
    }
    vector<ll> d(n + 1);
    REP(i, n + 1){
        d[c[i]]++;
    }
    vector<ll> r1(n + 1), r2(n + 1);
    for(ll i = 1; i <= n; i++){
        r1[i] += r1[i - 1];
        r1[i] += i * d[i];
        r2[i] += r2[i - 1];
        r2[i] += d[i];
    }
    auto f = [&](ll x){
        return (r1[x] + x * (r2[n] - r2[x])) / x;
    };
    ll ans = n;
    REP(i, n){
        while(ans > 0 && i + 1 > f(ans)) ans--;
        cout << ans << endl;
    }
}