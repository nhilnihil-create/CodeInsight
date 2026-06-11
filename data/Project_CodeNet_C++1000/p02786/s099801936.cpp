#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll h;
    cin >> h;
    ll cnt = 1;
    ll ans = 0;
    while(h > 0){
        h /= 2;
        ans += cnt;
        cnt *= 2;        
    }    
    cout << ans << endl;    
    return 0;
}