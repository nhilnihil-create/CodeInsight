/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
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
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> sum(n + 1, 0);
    for(int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + a[i];
        sum[i + 1] %= k;
    }

    for(int i = 0; i <= n; i++){
        sum[i] -= i;
        sum[i] %= k;
        if(sum[i] < 0) sum[i] += k;
    }

    map<int,int> mp;
    queue<int> q;
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans += mp[sum[i]];
        mp[sum[i]]++;
        q.push(sum[i]);
        if(q.size() >= k){
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;

    
}