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
    ll K;
    cin >> S >> K;
    ll N = S.length();
    ll l = 0;
    ll r = 0;
    ll out = 0;
    if(S[0]==S[N-1]){
        rep(i,N){
            if(S[i]==S[0]) l++;
            else break;
        }
        if(l!=N){
            rep(i,N){
                if(S[N-1-i]==S[N-1]) r++;
                else break;
            }
            out += l/2 + r/2 + (l+r)/2*(K-1);
        }else{
            r=N;
            out = N*K/2;
        }
    }
    for(ll i=l;i<N-r;i++){
        if(S[i]==S[i+1]){
            out += K;
            i++;
        }
    }
    cout << out << endl;
    return 0;
}
