#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nchoose2 ( ll a )
{
  return a*(a-1)/2;
}
int main()
{
    ll n;
    cin>>n;
    ll* a = new ll[n+1]();
    ll* b = new ll[n]();
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        a[ b[i] ]++;
    }
    ll totalans =0;
    for(int i=0;i<=n;i++)
    {
        totalans = totalans + nchoose2(a[i]);
    }
    for(int i=0;i<n;i++)
    {
         if( a[b[i] ] < 2 )
             cout<<totalans<<endl;
         else
         {
             ll temp = totalans - nchoose2(a[b[i]]) + nchoose2(a[b[i]] -1 );
             cout<<temp<<endl;
         }
    }
}