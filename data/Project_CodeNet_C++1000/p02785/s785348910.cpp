#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    long long int n,k,ans=0;
    cin>>n>>k;
    vector<long long int> h(n);
    rep(i,n) cin>>h[i];
    sort(h.begin(),h.end());
    rep(i,n-k) ans+=h[i];
    cout<<ans;
}