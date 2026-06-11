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

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll A[N];
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    ll out[N];
    out[0] = 0;
    ll tmp = 0;
    ll out_sum = 0;
    while(tmp!=N-2){
        if(tmp==N-1){
            out[1] = out[N-1] + 2*(A[0]-A[N-1]);
            out_sum += out[1];
            tmp = 1;
        }else{
            out[tmp+2] = out[tmp] + 2*(A[tmp+1]-A[tmp]);
            out_sum += out[tmp+2];
            tmp += 2;
        }
    }
    rep(i,N){
        cout << out[i]+(sum-out_sum)/N;
        if(i==N-1) cout << endl;
        else cout << " ";
    }
    return 0;
}
