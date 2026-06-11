#include<bits/stdc++.h>
#define mod 1000000007
// #define pie 3.141592653589793238
#define mod1 998244353
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int li;
typedef unsigned long long int ull;
using namespace std;
bool sortbysec(const pair<li,li>&a,const pair<li,li>&b)
{
    return (a.second<b.second);
}
li mpow(li x,li y)
{
  li ans=1;
  while(y)
  {
    if(y%2!=0)
    ans=(ans%mod)*(x%mod)%mod;
    y/=2;
    x=((x%mod)*(x%mod))%mod;
  }
  return ans;
}
li nCrModp(int n, int r)
{
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;

    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    li C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++) {

        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % mod;
    }
    return C[r];
}
int main()
{
fast_io
li n,k,i,j;
cin>>n>>k;
li ans[k+1];
ans[k]=1;
li a=0;
for(i=k;i>=1;i--)
{
  li x=k/i;
  li p=0;
  x=mpow(x,n);
  for(j=2*i;j<=k;j+=i)
  {
    p=(p%mod+ans[j]%mod)%mod;
  }
  ans[i]=(x-p+mod)%mod;
  a=(a%mod+((ans[i]%mod)*(i%mod))%mod)%mod;
}
cout<<a;
  return 0;
}
