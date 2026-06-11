


#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define inf    0x3f3f3f3f
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef vector<int>      vi;
typedef vector<bool>     vb;
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

 int main(){

  ll x,k,d;
  cin>>x>>k>>d;

  x = abs(x);

  if(x > 0 && x/d >= k){
      x = x - k*d;
      cout<<abs(x)<<endl;
      return 0;
  }

  ll y = x/d;
  x -= y*d;
   k -= y;

   if(k%2 == 0)
      cout<<abs(x)<<endl;
   else if(k%2== 1){
      ll ans = min(abs(x+d),abs(x-d) );
      cout<<ans<<endl;
   }

return 0;
 }

