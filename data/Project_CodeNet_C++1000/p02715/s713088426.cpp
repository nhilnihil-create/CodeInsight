#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
const int mod = 1e9+7;
ll mod_pow(ll a, ll b){
    if(!a)return a;
    ll res = 1;
    while(b){
        if(b&1)res = res * a % mod;
        a = a * a % mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> dp(k + 1);
    ll ans = 0;
    for(int i = k; i >= 1; i--){
        //dp[i] = (k/i)^n - dp[i*2]
        dp[i] = mod_pow(k / i, n);
        for(int j = 2 * i; j <= k; j+=i){
            dp[i] -= dp[j];
            if(dp[i] < 0)dp[i] += mod;
        }
        ans += dp[i] * i;
        ans %= mod;
    }
    cout << ans << endl;
    
}
