#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,ans=0;
    cin >> a >> b;
    while(true){
        if(ans*2/25==a && ans/10==b){
            cout << ans << endl;
            break;
            }
        ans++;
        if(ans>=10000){
            cout << -1 << endl;
            break;
            }
    }
    return 0;
}