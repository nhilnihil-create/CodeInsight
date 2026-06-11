#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
const int MOD = 1e9 + 7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int D,T,S;
    cin >> D >> T >> S;
    if(D <= T * S){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}