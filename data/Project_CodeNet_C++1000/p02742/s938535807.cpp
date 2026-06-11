#include <bits/stdc++.h>
using namespace std;
 
int main() {

    long long H, W;
    cin >> H >> W;
    long long ans;

    if(H % 2 == 0){
        ans = (H / 2) * W;
    }else{
        if(W % 2 == 0){
            ans = ((H / 2) + 1) * (W / 2) + (H / 2) * (W / 2);
        }else{
            ans = ((H / 2) + 1) * ((W / 2) + 1) + (H / 2) * (W / 2);
        }
    }

    if(H == 1 || W == 1){
        ans = 1;
    }

    cout << ans << endl;

}