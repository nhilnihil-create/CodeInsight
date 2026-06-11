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

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll mod = 1000000007;
    ll N,K;
    cin >> N >> K;
    ll A[N];
    rep(i,N) cin >> A[i];
    ll S = 0;
    rep(i,N){
        for(ll j=i+1;j<N;j++){
            if(A[i]>A[j]) S++;
        }
    }
    ll out = (S*K)%mod;
    ll T = 0;
    rep(i,N){
        rep(j,N){
            if(A[i]>A[j]) T++;
        }
    }
    out = (out+((K*(K-1))/2)%mod*T)%mod;
    cout << out << endl;
    return 0;
}
