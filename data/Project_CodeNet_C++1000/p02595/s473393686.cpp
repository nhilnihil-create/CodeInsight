#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define P pair<ll, ll>

typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    ll n, d;
    cin >> n >> d;
    ll x[n], y[n];
    rep(i, n) cin >> x[i] >> y[i];
    ll ans = 0;
    rep(i, n) {
        if(x[i] * x[i] + y[i] * y[i] <= d * d) ans++;
    }
    cout << ans << endl;
}