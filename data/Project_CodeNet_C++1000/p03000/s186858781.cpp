#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n,x,ans=1;
    cin>>n>>x;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    for(int i=1;i<n;i++)
        l[i]=l[i-1]+l[i];
    rep(i,n)
    {
        if(l[i]>x) break;
        ans++;
    }
    cout<<ans;
}