#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n,m,k;
   cin>>n>>m>>k;
   vector<ll>a;
   vector<ll>b;
  ll t;
   for(int i=0;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
   for(int i=0;i<m;i++)
    {
        cin>>t;
        b.push_back(t);
    }

    vector<ll>sum_a(n+1);
    sum_a[0]=0;
   for(int i=1;i<=n;i++)
    sum_a[i]=sum_a[i-1]+a[i-1];

   vector<ll>sum_b(m+1);
   sum_b[0]=0;
   for(int i=1;i<=m;i++)
    sum_b[i]=sum_b[i-1]+b[i-1];

   ll ans=0;ll other;ll temp;
   for(int i=0;i<=n;i++)
   {
       other=k-sum_a[i];
       if(other<0)
        break;
        int l=lower_bound(sum_b.begin(),sum_b.end(),other)-sum_b.begin();
        if(l>m||sum_b[l]>other)
            l--;
            temp=i+l;
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
