#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;
const int mxn=10000005;
vector<int> p;
map<int,bool> mp;
ll a,b;

void fact(ll a)
{
  for(ll i=2;i*i<=a;i++)
  {
    if(a%i==0)
    {
      while(a%i==0)
        a/=i;
      if(!mp[i])
      {
        p.pb(i);
        mp[i]=1;
      }
    }
  }
  if(a!=1)if(!mp[a])
  {
    p.pb(a);
    mp[a]=1;
  }
} 

int main()
{
  fastio;
  p.pb(1);
  cin>>a>>b;
  fact(__gcd(a,b));
  int ans=0;
  for(int i=0;i<p.size();i++)
  {
      ans++;
  }
  cout<<ans<<endl;
}
