#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
const int N=1e9+7;
#define int long long
#define double long double
int mod_expo_iterative(int x, int y,  int mod) {
  int an = 1;
  while(y>0) {
    if(y&1) {
      an = (an*x)%mod;
    }
    x = (x*x)%mod;
    y/=2;
  }
  return (int)an;
}
int32_t main()
{
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
 IOS;
int n;
cin>>n;
int ans=mod_expo_iterative(10ll,n,N)-(2*mod_expo_iterative(9ll,n,N))%N+mod_expo_iterative(8ll,n,N)+N;
ans%=N;
cout<<ans;
 	



  
 




  
return 0;
}
