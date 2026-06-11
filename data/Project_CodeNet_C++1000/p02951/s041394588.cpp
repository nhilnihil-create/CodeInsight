#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795

ll no_of_div(ll a)
{
  ll cnt=0,i;
  if (a==2)return 1;
  for(i=2;i*i<a;i++)
  {
if(a%i==0)cnt+=2;
  }
  if(i*i==a)cnt++;
  return cnt;
}

//vl a(1001);

ll powM(ll a,ll b)
{ 
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }

return ans;
}







int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


ll a,b,c;cin>>a>>b>>c;

cout<<max((ll)0,(c+b-a))<<"\n";





  return 0;


}