#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
    int n;cin>>n;
    vector<int>a(n+1);rep(i,n+1)cin>>a[i];
    vector<int>b(n);rep(i,n)cin>>b[i];
    ll ans=0;
    rep(i,n+1){
        if(i==0){
            if(a[i]>b[i]){
                ans=b[i];
                 b[i]=0;
            }else{
                ans=a[i];
                b[i]=b[i]-a[i];
            }
            continue;
        }
        if(a[i]>b[i]+b[i-1]){
            ans=ans+b[i]+b[i-1];
            b[i]=0;
        }else{
            ans=ans+a[i];
            if(a[i]<b[i-1]){
            }else{
                b[i]=b[i]-a[i]+b[i-1];
            }
        }
    }

cout<<ans;

}