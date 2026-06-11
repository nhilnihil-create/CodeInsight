#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int n;
    cin >> n;

    long long ans=1, a;
    bool zero = false, over = false;
    rep(i, n){
        cin >> a;
        if(a == 0){
            zero = true;
        } else if(ans <= 1000000000000000000 / a){
            ans *= a;
        } else {
            over = true;
        }
    }
    
    if(zero){
        cout << 0 << endl;
    } else if(over){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;

}