#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

ll modpow(ll a,ll n,ll m) {
    if(n==1) return a%m;
    if(n%2==1) return (a*modpow(a,n-1,m))%m;
    ll b = modpow(a,n/2,m)%m;
    return (b*b)%m;
}

int main() {
    ll mod = 1000000007;
    ll X,Y;
    cin >> X >> Y;
    ll out = 0;
    vector<pair<ll,ll>> p;
    rep(i,X+1){
        if((X-i)%2==0&&(X-i)/2==Y-2*i&&Y-2*i>=0){
            p.push_back(make_pair(i,(X-i)/2));
        }
    }
    rep(i,p.size()){
        ll A = 1;
        rep(j,p[i].first+p[i].second) A = (A*(j+1))%mod;
        ll B = 1;
        rep(j,p[i].first) B = (B*(j+1))%mod;
        ll C = 1;
        rep(j,p[i].second) C = (C*(j+1))%mod;
        out = (A*modpow((B*C)%mod,mod-2,mod))%mod;
    }
    cout << out << endl;
    return 0;
}
