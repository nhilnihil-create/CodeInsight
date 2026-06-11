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
ll ans[200000];
ll m=1e9+7;
int main()
{
   ll n,i,j;
   cin>>n;
    ans[0]=1;
    for(i=3;i<=n;i++)
    {
      for(j=3;j<=i;j++)
      {
        ans[i]+=ans[i-j];
        ans[i]=ans[i]%m;
      }
    }
    cout<<ans[n]<<endl;

}