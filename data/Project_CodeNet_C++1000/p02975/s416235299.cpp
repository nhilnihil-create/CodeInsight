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
ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}




int main(){
  ll N;
  cin >> N;
  vector<ll> a(N);
  for(auto &&x:a)cin>>x;

  map<ll,ll> ma;
  for(auto x:a){
    ma[x]++;
  }

  if(ma[0] == N){
    cout << "Yes" << endl;
  }else if(N%3!=0){
    cout << "No" << endl;
  }else if(ma.size()==2 && ma[0]*3 == N){
    cout << "Yes" << endl;
  }else{
    bool ok = true;
    for(auto x:ma){
      if(x.first==0 && x.second==0)continue;
      //cout << x.first << " " << x.second << endl;
      if( x.second*3 != N)ok=false;
    }
    ll k = 0;
    for(auto x:a)k ^= x;
    if(k!=0) ok = false;
    cout << ( ok ? "Yes" : "No" ) << endl;
  }



}
