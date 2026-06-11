#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld= long double;
using ull= unsigned long long;
#define endl "\n"

const ll maxn=3e5+100;

const ll maxx=1e13;
const ll mod=1000000007;


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
   ll kq=0;
   for (int i=1;i<=n;i++)
   {
       ll t=i-k;
       if (t>0)
       {
           mp[f[t]]--;
       }
       if (f[i]==0)
       {
           kq=kq+mp[0];
           if (i<k) kq++;

       }
       else
       {
           kq=kq+mp[f[i]];
       }
       mp[f[i]]++;
   }
   cout << kq;
}
