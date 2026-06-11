#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n,ans=1e9;
    cin>>n;
    vector<int> a(n);
    int l=101,r=0;
    rep(i,n){
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    for(int i=l;i<=r;i++){
        int num=0;
        for(int j=0;j<n;j++){
            num+=(a[j]-i)*(a[j]-i);
        }
        ans=min(num,ans);
    }
    cout<<ans;
}