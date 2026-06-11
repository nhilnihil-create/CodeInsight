#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define fi first
#define se second
#define pb push_back
#define soo(v) sort(v.rbegin(),v.rend())
#define so(v) sort(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define endl '\n'
#define dbv(v) cout<<endl;cout<<#v<<"-->> ";for(auto it:v){cout<<it.fi<<" "<<it.se<<endl;}cout<<endl;
#define dbm(m)cout<<endl;cout<<#m<<"-->> ";for(auto it:m){cout<<it.fi<<" "<<it.se.fi<<" "<<it.se.se<<endl;}
#define dbs(s)cout<<endl;cout<<#s<<"-->> ";for(auto it:s){cout<<it<<" ";}cout<<endl;
#define mod 1000000007
#define db1(x) cout<<#x<<"="<<x<<endl;
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl;
//#define mx 1e18
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define double long double
#define io std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define re(s) reverse(s.begin(),s.end())

int32_t main()
{
 io
  int n;
  cin>>n;
  vector<pair<int,int>>v(n);int x,y;vector<pair<int,int>>a,b;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    v[i]={x,y};
    
  }
  so(v);
  for(int i=0;i<n;i++)
  {
    a.pb({v[i].fi,v[i].fi+v[i].se});
    b.pb({v[i].fi,v[i].fi-v[i].se});
  }

int ans=0;
so(a);
so(b);
int mx=INT_MAX;

for(int i=0;i<a.size();i++)
{
    if(i==0)
    {
      mx=min(mx,a[i].se);
    }
    else
    {
      ans=max(ans,a[i].se-mx);
      mx=min(mx,a[i].se);
    }
}
mx=INT_MAX;
for(int i=0;i<b.size();i++)
{
   if(i==0)
   {
    mx=min(mx,b[i].se);
   }
   else
   {
     ans=max(ans,b[i].se-mx);
     mx=min(mx,b[i].se);
   }
}
cout<<ans<<endl;


}
