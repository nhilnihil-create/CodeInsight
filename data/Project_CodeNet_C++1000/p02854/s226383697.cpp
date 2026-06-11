#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n), s(n+1, 0);
    rep(i, n){
        cin >> a[i];
    }
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    ll mina = s[n];
    rep(i, n){
        // cout << s[i] << " " << s[n] - s[i] << endl;
        mina = min(mina, abs(s[i] - (s[n] - s[i])));
    }


    cout << mina << endl;

}