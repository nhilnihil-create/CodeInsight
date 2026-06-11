#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    int n;cin>>n;
    vector<int> a(n+1),b(n);
    rep(i,n+1)cin>>a[i];
    rep(i,n)cin>>b[i];
    ll ans=0;
    rep(i,n){
        if(a[i]<b[i]){
            if(a[i+1]<b[i]-a[i]){
                ans+=a[i]+a[i+1];
                a[i+1]=0;
            }
            else{
                ans+=b[i];
                a[i+1]-=b[i]-a[i];
            }
        }
        else{
            ans+=b[i];
            a[i]-=b[i];
        }
    }
    cout<<ans<<endl;
}