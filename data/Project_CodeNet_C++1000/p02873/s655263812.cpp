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

    string S;
    cin >> S;
    ll N = S.length();
    ll L[N+1];
    rep(i,N+1){
        if(i==0) L[0] = 0;
        else{
            if(S[i-1]=='<') L[i] = L[i-1]+1;
            else L[i] = 0;
        }
    }
    ll R[N+1];
    rep(i,N+1){
        if(i==0) R[N] = 0;
        else{
            if(S[N-i]=='>') R[N-i] = R[N-i+1]+1;
            else R[N-i] = 0;
        }
    }
    ll out = 0;
    rep(i,N+1) out += max(L[i],R[i]);
    cout << out << endl;
    return 0;
}
