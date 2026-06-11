#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,l,a[100000],st,go,mid;
ll f(ll x){
    vector<ll> v;
    ll cnt=0;
    if(n-x<=l)return 1;
    for(int i=x+1;i<=n-l;i++){
        if(a[x]+m-a[i]<0)return 0;
        cnt+=min(m,a[x]+m-a[i]);
    }
    if(max(0LL,k-l-x)*m>cnt)return 0;
    return 1;
}
int main(void){
    cin>>n>>m>>k>>l;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    st=-1;go=n-1;
    while(go-st>1){
        mid=(go+st)/2;
        if(f(mid)==1)go=mid;
        else st=mid;
    }
    cout<<n-go<<endl;
}
