/*
    Author:zeke

    pass System Test!
    GET AC!!
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 998244353;
ll INF = 1e18;
// cout << "Case #" << index << " :IMPOSSIBLE";
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    ll n,s;
    cin>>n>>s;
    V vec(n);
    rep(i,n)cin>>vec[i];
    VV dp(n+1,V(s+1));
    //S&T
    //T not S
    //not T&S
    dp[0][0]=1;
    rep(i,n){
        rep(j,s+1){
            dp[i+1][j]+=2*dp[i][j];
            dp[i+1][j]%=MOD;
            if(j+vec[i]<=s){
                dp[i+1][j+vec[i]]+=dp[i][j];
                dp[i + 1][j + vec[i]] %= MOD;
            }
        }
    }
    cout<<dp[n][s]<<endl;
}
