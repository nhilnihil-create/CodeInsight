#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)
#define fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%lld", &n)
#define sff(a,b) scanf("%lld %lld", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define f find
#define ub upper_bound
#define lb lower_bound
#define ld long double
#define in insert
#define bs binary_search  
#define le length()
const ll max_i=1e15;
#define np(s) next_permutation(s.begin(),s.end())
//it gives the lexicographically next string
 ll GCD(ll a,ll b)
    {
        if(b==0)
            return a;
        else return GCD(b,a%b);
    }
int main()
{
  int t=1;
  //cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
  int ans=0,p=1;
  for(int i=1;i<n;i++)
  {
    if(arr[i]<=arr[i-1]) p++;
    else
    {
      ans=max(p,ans);
      p=1;
    }
  }
  ans=max(p,ans);
  cout<<ans-1;
  }
  return 0;
}
