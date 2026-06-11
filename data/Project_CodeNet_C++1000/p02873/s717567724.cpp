#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()

ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}



int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);



string s;cin>>s;
ll count=0;

vector<ll>v1,v2;

char cur=s[0];
if(cur!='<')v1.pb(0);
for(char x:s)
{
if(x==cur)
{
  count++;
}
else 
{
  if(cur=='<')v1.pb(count);
  else v2.pb(count);
  count=1;
  cur=x;
}

}

ll ans=0;

 if(cur=='<')v1.pb(count);
  else v2.pb(count);



  if(v1.size()<v2.size())v1.pb(0LL);
  else if(v1.size()>v2.size())v2.pb(0LL);

  //  for(auto x:v1)cout<<x<<" ";

for(int i=0;i<v1.size();i++)
{
  ll a=min(v1[i],v2[i]);
  ll b=max(v1[i],v2[i]);

  ll temp=a*(a-1)+b*(b+1);
  ans+=temp/2;
}

cout<<ans<<"\n";


return 0;

}
