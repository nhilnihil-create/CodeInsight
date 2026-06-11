#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define rep(a,n) for(int i=a;i<n;i++)
#define rep1(a,n) for(int i=a;i<=n;i++)
#define bada 1000000007
ll c[2001][2001];
int main()
{
    for(int i=0;i<=2000;i++)
   {
    c[i][0]=c[i][i]=1;
    for(int j=1;j<i;j++)
    {
       c[i][j]=(c[i-1][j])+(c[i-1][j-1]);
       c[i][j]%=bada;
    }
   }
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=k;i++)
      cout<<(c[n-k+1][i]*c[k-1][i-1])%bada<<"\n";

   return 0;
}
