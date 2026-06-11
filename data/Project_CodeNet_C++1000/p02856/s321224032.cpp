#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll dfs(ll i, ll n) {
    if(i*n < 10) return (n-1);
    ll base = 0, cur = 0;
    while(cur < 10){
        cur += i;
        base++;
    }
    cur -= 9;
    ll div = n / base;
    ll rem = n % base;
    ll res = dfs(cur, div) + div;
    rep(j, 0, rem){
        cur += i;
        res++;
        if(cur > 9) {
            cur -= 9;
            res++;
        }
    }
    return res;
}

int main(){
    ll m;
    cin >> m;
    vector<ll> d(m), c(m);
    rep(i, 0, m) cin >> d[i] >> c[i];
    ll digit = 0, sum = 0;
    rep(i, 0, m) {
        digit += c[i];
        sum += d[i] * c[i];
    }
    cout << digit - 1 + (sum - 1) / 9 << endl;
    return 0;
}