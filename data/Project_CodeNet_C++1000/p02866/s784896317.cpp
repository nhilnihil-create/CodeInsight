#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;

ll modpow(ll base, int p) {
    ll mul = base;
    ll ret = 1;
    while (p) {
        if (p&1) {
            ret *= mul;
            ret %= MOD;
        }
        mul *= mul;
        mul %= MOD;
        p >>= 1;
    }
    return ret;
}

int main() {
    int n; 
    cin >> n;
    unordered_map<int, int> mp;
    int maxa = 0;
    vector<int> va(n); 
    rep(i, n) {
        int as; 
        cin >> va[i];
        mp[va[i]]++;
        maxa = max(maxa, va[i]);
    }
    if (mp[0] != 1 || va[0] != 0) {
        cout << 0 << endl;
        return 0;
    } 
    ll ret = 1;
    ll pre = 1;
    for (int a = 1; a <= maxa; ++a) {
        if (mp[a] == 0) {
            ret = 0;
            break;
        }  
        ret *= modpow(pre, mp[a]);
        ret %= MOD; 
        pre = mp[a];
    }
    cout << ret << endl;
    return 0;
}