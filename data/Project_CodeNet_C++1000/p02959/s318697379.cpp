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

    ll N;
    cin >> N;
    ll A[N+1];
    rep(i,N+1) cin >> A[i];
    ll B[N+1];
    rep(i,N) cin >> B[i];
    B[N] = 0;
    ll out = 0;
    ll add = 0;
    rep(i,N+1){
        if(A[i]<B[i]+add){
            out += A[i];
            add = min(B[i]+add-A[i],B[i]);
        }else{
            out += B[i]+add;
            add = 0;
        }
    }
    cout << out << endl;
    return 0;
}
