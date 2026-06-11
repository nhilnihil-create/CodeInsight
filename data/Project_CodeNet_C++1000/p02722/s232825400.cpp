#include <bits/stdc++.h>
#define ll long long
#define V vector<long long>
#define VV vector<vector<long long>>
#define VVV vector<vector<vector<long long>>>
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main() {
    ll n;
    cin>>n;
    if(n==2){
        cout<<1<<endl;
        return 0;
    }
    ll ans=0;
    ll sq=sqrt(n-1);
    if(sq*sq==n-1){
        ll tmp=0;
        for(int i=2;i<sq;i++){
            if((n-1)%i==0)tmp++;
        }
        ans+=tmp*2+2;
    }else{
        ll tmp=0;
        for(int i=2;i<=sq;i++){
            if((n-1)%i==0)tmp++;
        }
        ans+=tmp*2+1;
    }
    V div;
    ll sqq=sqrt(n);
    for(int i=2;i<=sqq;i++){
        if(n%i==0){
            div.push_back(i);
            if(!(sqq*sqq==n && i==sqq))div.push_back(n/i);
        }
    }
    div.push_back(n);
    for(int i=0;i<div.size();i++){
        ll p=n;
        while(p%div[i]==0)p/=div[i];
        if(p%div[i]==1)ans++;
    }
    cout<<ans<<endl;
}
