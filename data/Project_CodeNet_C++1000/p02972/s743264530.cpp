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

int main() {
    ll N;
    cin >> N;
    ll a[N];
    rep(i,N) cin >> a[i];
    ll M = 0;
    ll b[N];
    rep(i,N) b[i] = 0;;
    rep(i,N){
        ll I = N-1-i;
        ll n = N/(I+1);
        ll cnt = 0;
        rep(j,n){
            if(b[(I+1)*(j+1)-1]==1) cnt++;
        }
        if(cnt%2!=a[I]){
            b[I]++;
            M++;
        }
    }
    cout << M << endl;
    rep(i,N){
        if(b[i]==1) cout << i+1 << endl;
    }
    return 0;
}

