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
    string S;
    cin >> S;
    ll N = S.length();
    ll cntL = 0;
    ll cntR = 0;
    ll r = 0;
    ll out[N];
    rep(i,N) out[i] = 0;
    rep(i,N){
        if(S[i]=='R'){
            if(S[i+1]=='R') cntR++;
            else{
                r = i;
                out[r] += 1+cntR/2;
                out[r+1] += 1+(cntR+1)/2;
                cntR = 0;
            }
        }else{
            if(S[i+1]=='L') cntL++;
            else{
                out[r] += (cntL+1)/2;
                out[r+1] += cntL/2;
                cntL = 0;
            }
        }
    }
    rep(i,N){
        cout << out[i];
        if(i<N-1) cout << " ";
        else cout << endl;
    }
    return 0;
}
