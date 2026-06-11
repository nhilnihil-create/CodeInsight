#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll H, W;
    cin >> H >> W;

    ll h_num = 0;
    ll ans = 0;
    if (H%2 == 0) {
        h_num = H/2;
        ans = h_num*W;
    }
    else {
        h_num = H/2+1;
        for (ll i=0; i<W; i++){
            if (i%2 == 0){
                ans += h_num;
            }
            else{
                ans += h_num - 1;
            }
        }
    }

    if ((H == 1) || (W == 1)) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}
