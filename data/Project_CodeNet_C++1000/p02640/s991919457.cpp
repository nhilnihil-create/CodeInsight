#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int X, Y;
    cin >> X >> Y;
    bool ans = false;
    rep(turu, X+1){
        int kame = X - turu;
        if(turu*2+kame*4==Y) ans = true;
    }
    cout << ((ans) ? "Yes" :"No") << endl;
    return 0;    
}