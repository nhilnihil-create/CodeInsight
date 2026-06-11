#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    int n,k;
    cin>>n>>k;
    if(k==1)cout<<0<<endl;
    else{
        n-=k;
        cout<<n<<endl;
    }   
}

signed main(){
    //while(1)
    solve();
}