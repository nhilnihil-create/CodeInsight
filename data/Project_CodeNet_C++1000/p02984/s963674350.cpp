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

vector<ll> m(1001,0);

int main(){

    ll n; cin >> n;
    ll pos = 1;
    vector<ll> a(n);
    vector<ll> ans(n+1,0);
    vector<ll> d(n+1);
    ll sum = 0;

    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    rep(i,n-1){
        d[i+1] = a[i+1]-a[i];
    }
    d[n] = a[n-1]-a[0];

    for(int i = 1; i <= n; i ++){
        d[i] *= 2;
    }

    ans[1] = 0;

    for(int i = 1; i < n-1; i += 2){
        ans[i+2] = ans[i] + d[i];
    }

    ans[2] = ans[n]-d[n];

    for(int i = 2; i <= n-2; i += 2){
        ans[i+2] = ans[i] + d[i];
    }

    for(int i = 1; i <= n; i ++){
        sum -= ans[i];
    }

    ans[1] = sum/n;
    cout << ans[1] << " ";

    for(int i = 2; i <= n; i ++){
        cout << ans[i] + ans[1] << " ";
    }



    return 0;
}