#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;

const int N=1e7;

ll v[N+10];

ll a[N+10];


bool compare(string  &a, string &b)
{
     string f=a+b,c=b+a;

     return f<c;
}

int main()
{
    ll n;

    cin>>n;

    ll ara[n+10];

    for(ll i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    ll lcm=ara[0],gcd=0,sum=0;

      for(ll i=1;i<n;i++)
      {
          gcd=__gcd(lcm,ara[i]);
          
          lcm=(lcm*ara[i])/gcd;
      }

      for(ll i=0;i<n;i++)
      {
          sum+=(lcm/ara[i]);
      }

      double ans=0,ans2=0;

      ans=sum,ans2=lcm;

      ans2=ans2/ans;

      cout<<setprecision(10)<<fixed;

      cout<<ans2<<endl;



}






