#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
 
int main(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    rep(i,n)cin>>a[i];
    ll ans=a[0];
    for(int i=1;i<n;i++){
        if(i%2)ans-=a[i];
        else ans+=a[i];
    }
    b[0]=ans;
    for(int i=1;i<n;i++){
        b[i]=(a[i-1]-b[i-1]/2)*2;
    }
    rep(i,n){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}