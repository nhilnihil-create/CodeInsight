#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    rep(i,n)cin>>a[i];
    ll lb=0,ub=inf;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        ll sum=0;
        rep(i,n){
            sum+=(a[i]+mid-1)/mid-1;
        }
        if(sum>k)lb=mid;
        else ub=mid;
    }
    cout<<ub<<endl;
}
