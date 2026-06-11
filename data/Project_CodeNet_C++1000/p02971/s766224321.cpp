#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
ll max(ll a,ll b)
{
  if (a>b) {

    return a;
  }
  return b;
}

ll min(ll a,ll b)
{
  if (a<b) {

    return a;
  }
  return b;
}

ll gcd(ll a,ll b)
{
  if (b==0) return a;
  return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
  return a/gcd(a,b)*b;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   int b[n];
   int minm=200001;
   int maxm=0;
   int maxm2=0;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       b[i]=a[i];
   }
   sort(b,b+n);
    maxm=b[n-1];
    maxm2=b[n-2];


    for(int i=0;i<n;i++)
    {
        if(a[i]!=maxm)
        cout<<maxm<<endl;
        else
        {
            cout<<maxm2<<endl;
        }
    }



    return 0;
}


