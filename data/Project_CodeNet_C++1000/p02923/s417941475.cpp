#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n,ans=0,now=0;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n-1){
        if(a[i]>=a[i+1]) now++;
        else now=0;
        ans=max(ans,now);
    }
    cout<<ans;
}