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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
    //   freopen("GREEDY.INP", "r", stdin);
    //  freopen("GREEDY.OUT", "w", stdout);
    ll n;
     cin>>n;
     if (n==2)
     {
         cout <<1;
         return 0;
     }
     vector<ll> ans;
     for (ll i=2;i*i<=n;i++)
     {
        if (n%i==0)
        {
           ans.pb(i);
           if (i*i!=n) ans.pb(n/i);
        }
     }
     ll cnt=0;
     ans.pb(n);
     for (auto p:ans)
     {
       //  cout <<p<<endl;
         ll t= n;
         while (t%p==0) t/=p;
         if (t%p==1)
         {
             cnt++;
          //   cout <<p<<endl;

         }
     }
     ll t= n-1;
     for (ll i=2;i*i<=t;i++)
     {
         if (t%i==0)
         {
             cnt++;
             if (t!=i*i) cnt++;
         }
     }
     cnt++;
     //31cout <<endl;
    /* for (int i=2;i<=n;i++)
     {
         ll t= n;
          while (t%i==0) t/=i;
          if (t%i==1)
          {
              cnt++;
            //  cout <<i<<endl;
          }
     }*/
      cout <<cnt;
}
