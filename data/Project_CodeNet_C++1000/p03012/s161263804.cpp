#include<bits/stdc++.h>
#define int long long
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int32_t main()
{
    FastIO;
    int n,t=0;
    cin>>n;
    int a[n],s=0,ans=INT_MAX;
    for(int i=0;i<n;++i)
    {
      cin>>a[i];
      s+=a[i];
    }
    //sort(a,a+n);
    for(int i=0;i<n-1;++i)
    {
      t+=a[i];
      s-=a[i];
      ans=min(ans,abs(s-t));
    }
    cout<<ans<<endl;


}