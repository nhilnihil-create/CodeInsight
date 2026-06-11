#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int inf=-1;
const int sz=1000010;

#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define gap ' '
#define lb lower_bound
#define ub upper_bound
#define SIN(x) sin(x * pi / 180.0)
#define COS(x) cos(x * pi / 180.0)
#define clr(x) memset(x,0,sizeof(x))
#define all(x) sort(x.begin(),x.end())
#define rall(x) reverse(x.begin(),x.end())
#define dbg puts("finding wrong")
#define case(x,y) printf("Case %lld: %lld\n",++x,y)
#define fastio ios::sync_with_stdio(false);cin.tie(0)


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
  fastio;
  int  i, n, g=0, c=0;
  
  cin>>n;
  vector<int>ar(n);
  vector<int>cnt(sz);
  
  for(i=0; i<n; i++)
  {
      cin>>ar[i];
      cnt[ar[i]]++;
      g=gcd(g,ar[i]);
  }
  
 for(i=2; i<=sz; i++)
 {
     c=0;
     for(int j=i; j<=sz; j+=i)
     {
         c+=cnt[j];
     }
     if(c>1)break;
 }
  if(i==sz+1)
  {
      printf("pairwise coprime\n");
  }
  else if(g==1)
  {
      printf("setwise coprime\n");
  }
  else printf("not coprime\n");
  
  return 0;
}
