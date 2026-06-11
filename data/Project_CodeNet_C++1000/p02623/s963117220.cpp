#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=1; i <= (ll)(n); i++)

int main(void){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1,0),b(m+1,0),A(n+1,0),B(m+1,0);
    rep(i,n){
        cin>>a[i];
        A[i]=A[i-1]+a[i];
    }
    rep(i,m){
        cin>>b[i];
        B[i]=B[i-1]+b[i];
    }
    ll ans=0,i,j=m;
    for(i=0;i<=n;i++){
        while(A[i]+B[j]>k && j>0){
            j--;
        }
        if(A[i]+B[j]<=k)ans=max(ans,i+j);
        else break;
    }
    cout<<ans<<endl;
}