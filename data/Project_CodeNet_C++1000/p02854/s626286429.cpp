#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    ll A[N+1];
    ll S[N+1];
    S[0] = 0;
    ll len = 0;
    for(int i = 1; i < N + 1; i++){
        cin >> A[i];
        len += A[i];
        S[i] = S[i-1] + A[i];
    }
    ll mn_dif = len;
    if(len % 2 == 0){
        for(int i = 1; i < N + 1; i++){
            ll sub = abs(S[i] - (len/2));
            mn_dif = min(mn_dif, sub);
        }
        cout << mn_dif * 2 << endl;
    }else{
        for(int i = 1; i < N + 1; i++){
            double sub = abs(S[i] - (double)len / 2);
            mn_dif = min((double)mn_dif, sub);
        }
        cout << (ll)mn_dif * 2 + 1 << endl;
    }
    return 0;
}