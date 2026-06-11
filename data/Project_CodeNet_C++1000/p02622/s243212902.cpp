#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string S, T;
    cin >> S >> T;
    int ans = 0;
    rep(i, S.size()){
        if(S.at(i) != T.at(i)) ans++;
    }
    cout << ans << endl;
}