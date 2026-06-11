#include<bits/stdc++.h>
using namespace std;
typedef       long long int      ll;
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);
#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       RESET(a, b)        memset(a, b, sizeof(a))
#define       gcd(a, b)          __gcd(a, b)
#define       MX                 300005
#define       MOD               1000000007
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
bool cmp(ll x,ll y)
{
   return x>y;
}
int main(void)
{
   ll x,y;
   vector<ll> r,c,rmx,cmx;
   set< pair<ll,ll> > st;
   ll h,w,m,ans=0;
      cin>>h>>w>>m;
      for(ll i=0;i<m;i++)
      {
         cin>>x>>y;
         st.insert(make_pair(x,y));
         r.push_back(x);
         c.push_back(y);
      }
      sort(r.begin(),r.end());
      sort(c.begin(),c.end());
      ll cnt=1,mxr=0;
      for(ll i=1;i<m;i++)
      {
         if(r[i]==r[i-1])
            cnt++;
         else
         {
            if(cnt>mxr)
               mxr=cnt;
            cnt=1;
         }
      }
      if(cnt>mxr)
         mxr=cnt;
      cnt=1;
      ll mxc=0;
      for(ll i=1;i<m;i++)
      {
         if(c[i]==c[i-1])
            cnt++;
         else
         {
            if(cnt>mxc)
               mxc=cnt;
            cnt=1;
         }
      }
      if(cnt>mxc)
         mxc=cnt;
      cnt=1;
      //cout<<mxr+mxc<<endl;
      for(ll i=1;i<m;i++)
      {
         if(r[i]==r[i-1])
            cnt++;
         else
         {
            if(cnt==mxr)
               rmx.push_back(r[i-1]);
            cnt=1;
         }
      }
      if(cnt==mxr)
         rmx.push_back(r[m-1]);
      cnt=1;
      for(ll i=1;i<m;i++)
      {
         if(c[i]==c[i-1])
            cnt++;
         else
         {
            if(cnt==mxc)
               cmx.push_back(c[i-1]);
            cnt=1;
         }
      }
      if(cnt==mxc)
         cmx.push_back(c[m-1]);
      cnt=1;
      //cout<<rmx.size()<<" "<<cmx.size();
      ll in=0;
      for(ll i=0;i<rmx.size();i++)
      {
         for(ll j=0;j<cmx.size();j++)
         {
            if(st.find(make_pair(rmx[i],cmx[j]))==st.end())
            {
               in=1;
               break;
            }
         }
      }
      if(in)
         cout<<mxr+mxc<<endl;
      else
         cout<<mxr+mxc-1<<endl;
      //cout<<ans<<endl;
   return 0;
}
