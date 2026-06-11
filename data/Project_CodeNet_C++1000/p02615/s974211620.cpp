#include <bits/stdc++.h>
#define ll         long long int 
#define pb         push_back
#define umap       unordered_map
#define mod        1000000007
#define all(x)     (x).begin(), (x).end()
#define MN(a,b,c)  min(a,min(b,c))
#define pr         pair<ll,ll>
#define F          first
#define S          second
#define mP         make_pair
#define f(i,n)     for(int i=0;i<n;i++)
#define f1(i,x,y)   for(int i=x;i<=y;i++)
#define f2(i,x,y)  for(int i=x;i>=y;i--)
//__builtin_popcount(x)
//__builtin_parity(x)   =(number of set bits)%2
//__builtin_clz(x)      to count the number of leading  zeroes 
//__builtin_ctz(x)      to count the number of trailing zeroes 
//__gcd(a,b)
using namespace std;
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
  int n;cin>>n;
  vector <int> v(n);
  f(i,n)cin>>v[i];
  sort(all(v));
  ll ans=0;
  int x=n-1;
  f2(i,n-1,0)
  {
    if(i==(n-1))
      {ans+=v[i];x--;}
    else
    {
      if(x>1)
        {ans+=(2*v[i]);x-=2;}
      else
        {ans+=v[i];x--;}
    }
    if(x==0)break;
  }
  cout<<ans;
 }


