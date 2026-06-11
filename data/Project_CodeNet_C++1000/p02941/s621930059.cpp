#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
//#define slld(t) scanf("%lld",&t)
//#define sd(t) scanf("%d",&t)
//#define pd(t) printf("%d\n",t)
//#define plld(t) printf("%lld\n",t)
#define vec vector < int >
#define vecp vector < pair < int , int > >
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define pii pair < int , int >
#define pll pair < ll , ll > 
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define mod  1000000007
#define N   200005
#define MAX 300005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcount
#define PI acos(-1)
//#define endl "\n"
 
const int inf = (int)1e18 + 10;

priority_queue < pii >  pq;
int a[N] , b[N];
signed main(){
  fast;
 

  int n , x , y , val , ans = 0;
  cin >> n;
  for(int i = 0 ; i < n ; i++)
       cin >> a[i];
  for(int i = 0 ; i < n ; i++){
       cin >> b[i];
       if(b[i] != a[i])
       pq.push(mp(b[i] , i));
     }
   int cnt = 0;
    while(pq.size() > 0){
          pii p = pq.top();
          pq.pop();
          x = p.ss;
          val = p.ff ;
          y = b[(x- 1 + n) % n] + b[(x + 1) % n];
          int r = (val - a[x])/y;
          if((val - a[x]) <  y){
            ans = -1;
            break;
          }
          
          ans += r;
          val = (val - a[x]) % y;
          b[x]  = val + a[x];
          if(b[x] != a[x]) 
          pq.push(mp(b[x]  , x));

    }
    
    cout << ans << endl;

 
}