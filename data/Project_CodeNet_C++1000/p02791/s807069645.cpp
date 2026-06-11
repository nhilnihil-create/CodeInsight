#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
    int n,ans=0,m;
    cin>>n;
    vector<int> a(n+1);
    rep(i,n) cin>>a[i];
    rep(i,n)
    {
        if(i!=1) m=min(m,a[i]);
        else m=a[i];
        if(m>=a[i]) ans++;
    }
    cout<<ans;
}