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

    ll n,k; cin >> n >> k;
    ll ans = 0;
    vector<ll> h(n);

    for(int i = 0; i < n; i ++){
        cin >> h[i];
    }

    sort(h.begin(),h.end());

    if(k >= n) cout << 0;
    else{
        for(int i = 0; i < n-k; i ++){
            ans += h[i];
        }
        cout << ans;
    }



    return 0;
}