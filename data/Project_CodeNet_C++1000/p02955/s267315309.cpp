#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b,tot,tot2,L,LL,ans;
ll a[500],A[500],s1[501],s2[501];
vector<ll> u;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot2+=a[i];
    }
    for(ll i=1;i*i<=tot2;i++){
        if(tot2%i==0){
            u.push_back(i);
            u.push_back(tot2/i);
        }
    }
    for(ll x:u){
        for(int i=0;i<n;i++){
            A[i]=a[i]%x;
        }
        sort(A,A+n);
        for(int i=0;i<=n;i++){
            s1[i]=0;
            s2[i]=0;
        }
        for(int i=0;i<n;i++){
            s1[i+1]=s1[i]+A[i];
            s2[i+1]=s2[i]+x-A[n-i-1];
        }
        for(int i=0;i<=n;i++){
            //cout<<s1[i]<<" "<<s2[n-i]<<endl;
            if(s1[i]==s2[n-i])LL=s1[i];
        }
        if(LL<=m)ans=max(ans,x);
    }
    cout<<ans<<endl;
}
