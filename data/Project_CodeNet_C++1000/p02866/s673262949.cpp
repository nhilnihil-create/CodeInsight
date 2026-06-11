#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
#define PI acos(-1)
#define fs first
#define sc second
#define debug freopen("1.in","r",stdin),freopen("1.out","w",stdout);
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll maxn = 1e6 + 10;
const ll mod = 998244353;

int n, arr[maxn];
ll ans = 1;
ll mul(ll x,ll y,ll z)
{
    return x * y % z;
}
ll qpow(ll m, ll k, ll p){
    ll res = 1 % p;
    while (k){
        if (k&1) res = res * m % p;
        m = m * m % p;
        k >>= 1;
    }
    return res;
}

int main(){
    ios;
    cin >> n;
    cin >> arr[1];
    if (arr[1] != 0){
        cout << 0;
        return 0;
    }
    for (int i = 2; i <= n; i ++){
        cin >> arr[i];
        if (arr[i] == 0){
            cout << 0;
            return 0;
        }
    }
    sort(arr + 1, arr + 1 + n);
    ll tmp = 1, tmpp = 1;
    for (int i = 2 ; i <= n; i ++){
        if (arr[i] - arr[i - 1] != 1 && arr[i] - arr[i - 1] != 0){
            cout << 0;
            return 0;
        }
        if (arr[i] == arr[i + 1])
            tmpp ++;
        else{
            ans = mul(ans, qpow(tmp, tmpp, mod), mod);
            tmp = tmpp;
            tmpp = 1;
        }
    }
    cout << ans;

    return 0;
}