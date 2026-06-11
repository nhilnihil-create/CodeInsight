#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main() {
    ll n, k;
    ll ans = 0;
    cin >> n >> k;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n){
        ll front = 0, back = 0;
        rep(j,i){
            if(a[j] < a[i]) front ++;
        }
        for(int j=i; j<n; j++){
            if(a[j] < a[i]) back ++;
        }
        ans += ((k * (k-1) / 2) % MOD) * (front + back) + back * k;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
