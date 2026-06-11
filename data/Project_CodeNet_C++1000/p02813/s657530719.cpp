#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll repow(ll k,ll n)
{
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        ans= (((ans)*k) )%mod;
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n],b[n],c[n],tm=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i=0;i<n;i++)
       {
          cin>>b[i];
          if(b[i]>a[i] && tm==1)
          {
              tm=0;
          }
       }
    sort(c,c+n);
    int ain,bin,ans=0;
    do{
            int ai=1,bi=1;
        for(int i=0;i<n;i++)
        {
           if(c[i]!=a[i])
           {
               ai=0;
           }
           if(c[i]!=b[i])
           {
               bi=0;
           }
        }
        if(ai+bi>=1)
        {
            if(ai)
                ain=ans;
            if(bi)
                bin=ans;
        }

        ans++;

    }
    while(next_permutation(c,c+n));
    //cout<<ain<<" "<<bin<<" ";
    cout<<abs(ain-bin);
}
