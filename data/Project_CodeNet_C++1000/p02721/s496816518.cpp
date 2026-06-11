#include<bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define endl "\n"

const ll maxn=5e5;

const ll maxx=1e13;
const ll mod=1000000007;
const ll mod1=998244353;

ll a[maxn];
map<ll,ll> mp;
string s[maxn];
ll l[maxn];
ll r[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
    //   freopen("GREEDY.INP", "r", stdin);
    //  freopen("GREEDY.OUT", "w", stdout);
   ll n,k,c;
    cin>> n>>k>>c;
    string s;
    cin>>s;
    s=" " +s ;
    ll cnt=0;
    ll cnt1=0;
     for (int i=1;i<=n;i++)
     {
          if (cnt==0)
          {
              if (s[i]=='x') continue ;
              else
              {
                  cnt1++;
                  cnt=c;
                  l[i]=cnt1;

              }
          }
          else
          {
              cnt--;
              if (s[i]=='o')
              {
              //    l[i]=cnt1;

              }
          }
     }

     cnt=0;
     cnt1=0;
      for (int i=n;i>=1;i--)
     {
          if (cnt==0)
          {
              if (s[i]=='x') continue ;
              else
              {
                  cnt1++;
                  cnt=c;
                  r[i]=k-cnt1+1;

              }
          }
          else
          {
              cnt--;
              if (s[i]=='o')
              {
                //  r[i]=k-cnt1;

              }
          }
     }
       for (int i=1;i<=n;i++)
     {
     //    cout <<l[i]<<" "<<r[i]<<endl;
     }
    vector<ll> ans;
     for (int i=1;i<=n;i++)
     {
         if (s[i]=='o')
         {
             if (r[i]==l[i]&&r[i]!=0)
             {
                 ans.pb(i);
             }
         }
     }
     for (auto p:ans)
     {
         cout <<p<<endl;
     }
}
