#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll H, ans = 0, buf = 0;
    cin >> H;
    while(true){
        if(H >= 1){
            H = floor(H/2);
            ans += pow(2, buf++);
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}