#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll H, W, ans;
    cin >> H >> W;
    if(H == 1 || W == 1) ans = 1;
    else if(H%2 != 0 && W%2 != 0)      ans = (H/2) * (W/2+1+W/2) + W/2+1;
    else if(H%2 == 0 && W%2 != 0) ans = (H/2) * (W/2+1+W/2);
    else if(H%2 != 0 && W%2 == 0) ans = (H/2) * W + W/2;
    else if(H%2 == 0 && W%2 == 0) ans = (H/2) * W;
    cout << ans << endl;
    return 0;
}