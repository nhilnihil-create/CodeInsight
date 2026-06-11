#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n,ans=0,before=-2;
    cin>>n;
    vector<int> a(n),b(n),c(n-1);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n-1) cin>>c[i];
    for(int i:a)
    {
        i--;
        ans+=b[i];
        if(i==before+1) ans+=c[before];
        before=i;
    }
    cout<<ans;
}