#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= (int)(n); i++)
 
int main(){
    int n; cin >> n;
    int ans = 0;
    rep(i, n){
        rep(j, n){
            rep(k, n){
                ans += gcd(i, gcd(j, k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
