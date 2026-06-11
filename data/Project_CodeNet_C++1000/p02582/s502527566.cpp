//Diljit Dosanjh is the best.
#include<bits/stdc++.h>
using namespace std;
#define bolt ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
const ld pi=3.1415926535897932384626433;
const int mod = 1000000007;
const ll inf = 1e18;
void solve()
{
   string s;
   cin>>s;
   ll k=0;
   ll ans=0;
   for (ll i=0;i<3;i++)
   {
      if (s[i]=='R')
      k++;
      else
      {
         ans=max(ans,k);
         k=0;
      }
   }
   ans=max(ans,k);
   cout<<ans<<endl;
}
int main()
{
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout); 
   #endif
   bolt;
   ll t;
   t=1;
   while(t--)
   {
      solve();
   }
}
