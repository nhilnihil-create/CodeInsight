#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int a[20],b[20],c[20];
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    rep(i,n) cin>>b[i];
    rep(i,n-1) cin>>c[i];
    rep(i,n){
        ans+=b[a[i]];
        if(i!=n-1&&a[i]+1==a[i+1]){
            ans+=c[a[i]];
        }
    }
    cout<<ans<<endl;
}