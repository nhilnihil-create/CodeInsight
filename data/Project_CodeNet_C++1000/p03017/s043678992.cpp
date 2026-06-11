#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

int main(void)
{
    ll N, A, B, C, D, i, h=-1, d2=-1;
    string S;

    cin >> N >> A >> B >> C >> D >> S;

    for(i=0; i<N-1; i++){
        if(S[i]=='#' && S[i+1]=='#' && i+1<D){
            h = i;
        }
        if(i>=1 && S[i-1]=='.' && S[i]=='.' && S[i+1]=='.' && i+1<=D){
            d2 = i;
        }
    }

    if(C < D){
        if(h+1>=A && h+1<=D-2){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }

    else if(C > D){
        if(B-1<=d2 && d2<=D-1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}