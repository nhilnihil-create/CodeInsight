#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    ll num[200010]={0};
    ll a[200010];
    rep(i,n){
        cin>>a[i];
        a[i]--;
        num[a[i]]++;
    }
    ll ans=0;
    rep(i, n){
        if(num[i]<=1) continue;
        ans+=num[i]*(num[i]-1)/2;
    }
    rep(i,n) cout<<ans-num[a[i]]+1<<endl;
}