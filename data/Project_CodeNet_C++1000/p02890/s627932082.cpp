#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;


int main(){
  ll n;
  cin >> n;
  vector<int> a(n);
  map<int,int> mp;
  rep(i,n){
    cin >> a[i];
    mp[a[i]]++;
  }

  vector<ll> b;
  for(auto it:mp){
    b.emplace_back(it.S);
  }
  sort(b.begin(),b.end());
  ll m= b.size();
  vector<ll> r(n+1,0);
  rep(i,n){ r[i+1] = r[i]+(i<m?b[i]:0); }

  REP(k,1,n+1){
    ll ok=-1,ng=n+1,mid=(ok+ng)/2;
    while(ng-ok>1){
      mid=(ok+ng)/2;
      ll pos = lower_bound(b.begin(),b.end(),mid) - b.begin();
      ll cnt = r[pos] + mid*(m-pos);      
      if(cnt >= mid*k){ 
        ok=mid; 
      }else{ 
        ng=mid; 
      }
    }
    ll ans = ok;
    cout << ans << ln;
  }
  return 0;
}