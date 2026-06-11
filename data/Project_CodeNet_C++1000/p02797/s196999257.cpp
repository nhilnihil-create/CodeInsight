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

    ll N,K,S;
    cin >> N >> K >> S;
    rep(i,K){
        cout << S;
        if(i!=N-1) cout << " ";
    }
    if(N!=K){
        ll s = S-1;
        if(S==1) s = 2;
        rep(i,N-K){
            cout << s;
            if(i!=N-K-1) cout << " ";
        }
    }
    cout << endl;
    return 0;
}
