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
    string S;
    cin >> N >> S;
    ll out = 0;
    rep(i,1000){
        string str = to_string(i);
        if(str.size()==1) str = "00" + str;
        else if(str.size()==2) str = "0" +str;
        ll cnt = 0;
        rep(j,N){
            if(S[j]==str[cnt]){
                cnt++;
                if(cnt==3){
                    out++;
                    break;
                }
            }
        }
    }
    cout << out << endl;
    return 0;
}
