#include <bits/stdc++.h>
#define MOD 998244353
#define pb push_back
#define ll long long int
#define con 1000000007

using namespace std;
int main()
{    
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     ll i,j,k,n,m;
     ll t;
     ll a,b;
     cin>>n>>m;
     if(m%2==0)
     {   j=1;
         k=m+1;
         for(i=0;i<m/2;i++)
         {
             cout<<j<<" "<<k<<"\n";
             j++;
             k--;
         }
         j=m+2;
         k=2*m+1;
         for(i=0;i<m/2;i++)
         {
             cout<<j<<" "<<k<<"\n";
             j++;
             k--;
         }
     }
     else
     {
         j=1;
         k=m;
         for(i=0;i<m/2;i++)
         {
             cout<<j<<" "<<k<<"\n";
             j++;
             k--;
         }
         j=m+1;
         k=2*m+1;
         for(i=0;i<=m/2;i++)
         {
             cout<<j<<" "<<k<<"\n";
             j++;
             k--;
         }
     }
}  
