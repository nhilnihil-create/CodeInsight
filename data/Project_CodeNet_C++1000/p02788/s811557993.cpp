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
int main(void){
    ll n, d, a;
    cin >> n >> d >> a;

    vector<pair<ll,ll>> vec(n);
    rep(i, n){
        ll x, h;
        cin >> x >> h;
        vec[i] = {x, h};
    }

    sort(all(vec));

    vector<ll> point(n);
    rep(i, n) point[i] = vec[i].first;

    queue<pair<ll,ll>> q;
    q.push({0, -1});
    ll nowd = 0;
    ll ans = 0;
    rep(i, n){
        while(!q.empty() && q.front().second < point[i]){
            nowd -= q.front().first;
            q.pop();
        }
        //ll r = lower_bound(all(point), point[i] + 2 * d) - point.begin();
        ll nec = 0;
        if(vec[i].second - nowd >= 0){
            if((vec[i].second - nowd) % a == 0){
                nec = (vec[i].second - nowd) / a;
            } else {
                nec = (vec[i].second - nowd) / a + 1;
            }
        }

        //cout << i << " " << nec <<  " " << nowd << endl;
        nowd += a * nec;
        ans += nec;

        q.push({a * nec, point[i] + 2 * d});
    }
    cout << ans << endl;
}