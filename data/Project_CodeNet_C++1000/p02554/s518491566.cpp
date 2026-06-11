#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
ll m=1e9+7; 
int main()
 {
  int t=1;
  //cin>>t;
  while(t--)
  {
    ll n,i,j,x,y,ans=1,ans1=1,ans2=1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
      ans=(ans*10)%m;
    }
    for(i=1;i<=n;i++)
    {
     ans1=(ans1*9)%m; 
    }
  
    ans2=1;
      for(i=1;i<=n;i++)
    {
     ans2=(ans2*8)%m; 
    }
    ans=ans-(2*ans1)%m+ans2;
    if(ans<0)  ans=(ans+m);
    cout<<ans<<endl;
     

  }

  return 0;
}
