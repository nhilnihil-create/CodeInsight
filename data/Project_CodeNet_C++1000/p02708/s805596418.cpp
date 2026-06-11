#include<bits/stdc++.h>
using namespace std;

#define int long long int 
const int mod=1e9+7;
int32_t main()
{
    int n,k;
    cin>>n>>k;
    int x=n,y=0;
    int make=0,last_make=0;
    for(int i=0;i<k;i++)
    {
        make+=y;
        y++;
        last_make+=x;
        x--;
    }
    int ans=(last_make-make+1)%mod;
      for(int i=k+1;k<=n && make<=last_make;k++)
      {
          make+=y;
          y++;
          last_make+=x;
          x--;
          ans=(ans+(last_make-make+1)%mod)%mod;
      }
      cout<<ans<<endl;
}