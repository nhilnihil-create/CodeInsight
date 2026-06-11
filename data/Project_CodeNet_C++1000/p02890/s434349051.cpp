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
    constexpr const int MAX_N = 300000;
    int n;
    scanf("%d", &n);
    int a[MAX_N], c[MAX_N + 1] = {};
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        c[a[i]]++;
    }
    int d[MAX_N + 1] = {};
    for(int i = 0; i <= n; i++){
        d[c[i]]++;
    }
    ll r1[MAX_N + 1] = {};
    int r2[MAX_N + 1] = {};
    for(ll i = 1; i <= n; i++){
        r1[i] += r1[i - 1];
        r1[i] += i * d[i];
        r2[i] += r2[i - 1];
        r2[i] += d[i];
    }
    auto f = [&](ll x) -> int {
        return (r1[x] + x * (r2[n] - r2[x])) / x;
    };
    int ans = n;
    for(int i = 0; i < n; i++){
        while(ans > 0 && i + 1 > f(ans)) ans--;
        printf("%d\n", ans);
    }
}
