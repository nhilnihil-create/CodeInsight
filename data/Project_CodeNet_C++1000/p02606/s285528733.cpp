using namespace std;
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
int a,l,r;
cin>>l>>r>>a;
int n=a;
int ans=0;
while (a<=r)
{
    if(a>=l&&a<=r)
    {
    ans++;
    }
    a=a+n;
}
cout<<ans<<endl;
}
int main()
{

FASTIO
 long long int t;
 t=1;
 while(t--)
  solve();
  return 0;
}
