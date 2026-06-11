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


vector<ll> enum_div(ll n){//yakusu
  vector<ll> ret;
  for(ll i=1 ; i*i<=n ; ++i){
      if(n%i == 0){
        ret.push_back(i);
        if(i*i!=n)ret.push_back(n/i);
      }
  }
  return ret;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  cin >> N;
  vector<ll> A(N);
  FOR(i,0,N) cin >> A[i];

  SORT(A);
  if(A[0] == 1 && N>1 && A[1] == 1){
    cout << 0 << endl;
    return 0;
  }
  if(A[0]==1 && N==1){
    cout << 1 << endl;
    return 0;
  }
  if(A[0] == 1 && N>1 && A[1] > 1){
    cout << 1 << endl;
    return 0;
  }

  vector<ll> se(1000007,0);

  ll ans = 0;
  FOR(i,0,N){
    bool ok = true;
    if(i!=(N-1) && A[i]==A[i+1])ok = false;
    for(auto x:enum_div(A[i])){
      if(se[x])ok = false;
    }
    ans += ok;
    se[A[i]]=1;
  } 
  cout << ans << endl;
}

