#include<bits/stdc++.h>

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rept(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()

using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll h[n];
    rep(i,n){
        cin>>h[i];
    }
    ll ans=0;
    sort(h,h+n);
    
    rept(i,n-k){
        ans+=h[i];
    }
    cout<<ans<<endl;


}

