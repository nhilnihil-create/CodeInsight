#include<bits/stdc++.h>
using namespace std;
long long c(int n,int r){
    const int mod=1000000007;
    long long x=1,g=1;
    for(int i=1;i<=r;i++){
        x*=(n-i+1);
        x%=mod;
        g*=i;
        g%=mod;
    }
    long long pow=g;
    g=1;
    for(int i=mod-2;i>0;i/=2){
        if(i%2)g*=pow;
        g%=mod;
        pow*=pow;
        pow%=mod;
    }
    x*=g;
    x%=mod;
    return x;
}
int main(){
    const int mod=1000000007;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        //並べ方: n-k+1 C i ,分け方: k-1 C i-1
        if(n-k+1<i)cout<<"0"<<endl;
        else cout<<c(n-k+1,i)*c(k-1,i-1)%mod<<endl;
    }
    return 0;
}