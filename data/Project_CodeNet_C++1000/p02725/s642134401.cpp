#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    int k,n,ans=0;
    cin>>k>>n;
    vector<int> a(n);
    rep(i,n)
    {
        cin>>a[i];
        if(i==0) continue;
        ans=max(a[i]-a[i-1],ans);
    }
    ans=max(ans,k-a[n-1]+a[0]);
    cout<<k-ans;
}