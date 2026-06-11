#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)

int main(){
    string S, T;
    int ans = 0;
    cin >> S >> T;
    rep(i,0,3){
        if (S[i] == T[i]){
            ans++;
        }
    }
    cout << ans << endl;
}