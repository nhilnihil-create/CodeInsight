#include<bits/stdc++.h>
#define ll             long long int
#define lb             lower_bound
#define fi             first
#define ub             upper_bound
#define se              second
#define mp             make_pair
#define vll            vector<ll>
#define mod            1000003
#define endl            "\n"
#define fast           ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb             push_back
#define sz               size()
#define all(v)         v.begin(),v.end()
#define allr(v)        v.rbegin(),v.rend()
#define inp(V,n)       for(int i=0;i<n;i++){cin >> V[i];}
#define oup(V,n)       {for(int i=0;i<n;i++){cout <<  V[i] << " "  ;} cout << endl;}
using namespace std;
ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
ll gcd(ll a, ll b)
{
    if (a == 0)
      return b;
    return gcd(b % a, a);
}
ll lcm(ll a, ll b)
{
   return (a*b)/gcd(a, b);
}
bool sortByVal(const pair<double,double> &a,
               const pair<double,double> &b)
{
    if(a.fi==b.fi)
    {
    return (a.second >b.second);
    }
    else
        return (a.fi<b.fi);
}
int main()
{ int t=1;
   //cin>>t;
   while(t--)
  { ll n,i,j,k;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
    ll ans=0;
  sort(a,a+n);
  for(i=0;i<n;i++)
  {
      for(j=i+1;j<n;j++)
      {
          for(k=j+1;k<n;k++)
          {
              if(a[i]==a[j] || a[i]==a[k]|| a[k]==a[j])
                continue;
              if(a[i]+a[j]>a[k])
                ans++;
          }
      }
  }
  cout<<ans<<endl;

  }
return 0;
}
