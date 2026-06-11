#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    int N;
    cin >> N;

    rep(i, N){
        for(int j = i + 1; j < N; j++){
            int ans = __builtin_ctz(i ^ j) + 1;
            cout << ans << (j < N - 1 ? ' ' : '\n');
        }
    }

}