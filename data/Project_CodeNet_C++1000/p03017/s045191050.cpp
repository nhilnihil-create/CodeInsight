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
    // 入力
    ll N,A,B,C,D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    string out = "Yes";
    rep(i,D-2){
        if(i>A-1&&S[i]=='#'&&S[i+1]=='#'){
            out = "No";
            break;
        }
    }
    if(out=="Yes"){
        if(C>D){
            out = "No";
            for(ll i=B-2;i<D-1;i++){
                if(S[i]=='.'&&S[i+1]=='.'&&S[i+2]=='.') out = "Yes";
            }
        }
    }
    cout << out << endl;
    return 0;
}
