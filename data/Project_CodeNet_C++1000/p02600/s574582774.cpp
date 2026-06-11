#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int ans;
    if(n<600) ans=8;
    else if(n<800) ans=7;
    else if(n<1000) ans=6;
    else if(n<1200) ans=5;
    else if(n<1400) ans=4;
    else if(n<1600) ans=3;
    else if(n<1800) ans=2;
    else ans=1;
    cout << ans << endl;
}