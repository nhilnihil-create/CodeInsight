#include<bits/stdc++.h>

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rept(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()

using namespace std;

int main(){
    ll h;
    ll n=1;
    ll ans=1;
    cin>>h;
    if(h>1){
        while(h>0){
            h=h/2;
            if(n!=1){
                ans+=n;
            } 
            n*=2;
        }
    }
    else{
        ans=1;
    }
    cout<<ans;

}

