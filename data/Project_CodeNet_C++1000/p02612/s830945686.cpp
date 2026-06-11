#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
    int  n, ans = 1000;
    cin >> n;
    rep(i, 10){
        if(n <= ans){
            ans -= n;
            break;
        }
        ans += 1000;
    }
    cout << ans << endl;
    return 0;
}