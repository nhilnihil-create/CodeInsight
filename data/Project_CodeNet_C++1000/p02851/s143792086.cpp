#include<bits/stdc++.h>

#define nguyendz the_best
using namespace std;

#define ll long long
#define endl "\n"
#define ld long double
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
#define setpre(x) fixed<<setprecision(x)


const ll maxn=3e5+100;

const ll maxx=1e13;
const ll mod=1000000007;
const ll mod1 =998244353;
const ll base=31;


map<ll,ll> mp;
ll f[maxn];
ll a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
   ll n, k;
   cin>>n>>k;
   for (int i=1;i<=n;i++)
   {
       cin>>a[i];
       a[i]=a[i]-1+k;
       a[i]%=k;
   }
   f[0]=0;
   for (int i=1;i<=n;i++)
   {
      f[i]=(f[i-1]+a[i])%k;
   }
   /*for (int i=1;i<=n;i++) cout <<f[i]<<" ";
   cout <<endl;*/
   ll ans=0;
   for (int i=1;i<=n;i++)
   {
       ll t=i-k;
       if (t>0)
       {
           mp[f[t]]--;
       }
       //cout <<mp[f[i]]<<" ";
       if (f[i]==0)
       {
           ans=ans+mp[0];
           if (i<k) ans++;

       }
       else
       {
           ans=ans+mp[f[i]];
       }
       mp[f[i]]++;
   }
   cout <<ans;
}
