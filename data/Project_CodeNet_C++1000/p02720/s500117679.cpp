#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}





int main(){
  ll K;
  cin >> K;
  vector<ll> ans,x;
  FOR(i,1,10)x.push_back(i);
  FOR(i,1,10)ans.push_back(i);
  FOR(i,0,1000){
    vector<ll> tmp;
    for(auto a:x){
      ll n = a%10;
      if(n-1>=0){
        tmp.push_back(a*10+n-1);
        ans.push_back(a*10+n-1);
      }
      if(n+1<10){
        tmp.push_back(a*10+n+1);
        ans.push_back(a*10+n+1);
      }
      tmp.push_back(a*10+n);
      ans.push_back(a*10+n);
    }
    x = tmp;
    if(x.size()>K)break;
  }
  SORT(ans);
  cout << ans[K-1] << endl;
}


