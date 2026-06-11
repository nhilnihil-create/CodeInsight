#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans;

    if(n>1799)  ans=1;
    else if(n>1599) ans=2;
    else if(n>1399) ans=3;
    else if(n>1199) ans=4;
    else if(n>999)  ans=5;
    else if(n>799)  ans=6;
    else if(n>599) ans=7;
    else ans=8;

    cout<<ans<<endl;
}

int main(){
    //int t;cin>>t;while(t--)
    solve();
}

