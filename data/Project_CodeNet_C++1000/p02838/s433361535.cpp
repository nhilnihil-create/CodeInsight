#include <bits/stdc++.h>

#define ll long long int
#define pf push_front
#define mod  1000000007
#define inf  1000000000000000000
#define pi  acos(-1.0)
#define maxn  1000009
#define endl '\n'
#define sorted(s)  sort(s.begin(),s.end())
#define reversed(s) reverse(s.begin(),s.end())
#define sortarr(a) sort(a,a+n)
#define slc(n) scanf("%I64d", &n)
#define sl(n)  scanf("%lld", &n)
#define sf(n)  scanf("%lf", &n)
#define si(n)  scanf("%d", &n)
#define sch(n)  scanf(" %c", &n)
#define ss(n)  scanf("%s", n)
#define prf printf
#define pb  push_back
#define fr first
#define sc second
#define all(a)  a.begin(),a.end()
#define forl(n) for(i=0;i<n;i++)
#define ison(n,j) (n&(1LL<<j))
#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
ll con[65],c[65];
int main()
{
   ll n,i,j,res=0;
   cin>>n;
   ll a[n+5];
   for(i=0;i<n;i++)
    cin>>a[i];
   for(i=0;i<n;i++)
   {
       for(j=0;j<64;j++)
       {
           if((bool)(a[i]&(1LL<<j)))
            con[j]++;
           else
            c[j]++;
       }
   }
   for(i=0;i<64;i++)
    {
        res+=(((con[i]*c[i])%mod)*((1LL<<i)%mod))%mod;//,cout<<con[i]<<" "<<c[i]<<endl;
        res%=mod;
    }
   cout<<res%mod<<endl;

    return 0;
}