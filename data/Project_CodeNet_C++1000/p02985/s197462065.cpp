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
ll n, k;
vector<vector<ll>> g;
ll ans;
ll nPrM(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}
void dfs(ll now, ll pa, ll depth){

    bool f = false;
    rep(i, g[now].size()){
        ll next = g[now][i];
        if(next == pa) continue;
        f = true;
        dfs(next, now, depth + 1);
    }
    
    if(depth == 1){
        ans *= nPrM(k - 1, max(0LL, (ll)g[now].size()));
    } else  {
        if(f){
            ans *= nPrM(k - 2, max(0LL, (ll)g[now].size() - 1));
        }
    }
    ans %= MOD;
    //cout << now << " " << ans << endl;

}
int main(void){

    cin >> n >> k;

    g.resize(n);

    rep(i, n - 1){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ans = k;

    dfs(0, -1, 1);

    cout << ans << endl;

    
}