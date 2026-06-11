#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;

    while(k--){
        if(c<=a) c*=2;
        else if(c<=b) c*=2;
        else if(b<=a) b*=2;
    }
    if(c>b && b>a)
    cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    //int t;cin>>t;while(t--)
    solve();
}

