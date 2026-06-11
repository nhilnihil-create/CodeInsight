#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
 int l,r,d;
    cin>>l>>r>>d;
  //  cout<<l<<" "<<r<<" "<<d<<" ";
    if(l>r)
        swap(l,r);
    int ans=(r/d)-(l/d);
    if(l%d==0)ans++;
    
    cout<<ans;
}


int main()
{
 ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--)
        solve();
}