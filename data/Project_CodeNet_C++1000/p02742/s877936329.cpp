#include <bits/stdc++.h>
#include <queue>
#include <tuple>

using namespace std;

int main(){
    long long H, W;
    cin >> H >> W;
    unsigned long long ans = 1;

    if (W == 1 || H==1){
        ans = 1;
    }else{

        if(W % 2 == 0){
            ans = H * W / 2;
        }else{
            ans = 0;
            for(int i=0; i<H; i++){
                if(i%2 == 0){
                    ans += W /2 + 1;
                }else{
                    ans += W /2;
                }
            }
        }

    }

    cout << ans << endl;
    return 0;

}