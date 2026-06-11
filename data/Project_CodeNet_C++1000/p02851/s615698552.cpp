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

const int mx=200010;
const ll mod=1e9+7;

 
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> r(mx,0);
  rep(i,n){ cin >> a[i]; a[i]--; }
  rep(i,n){ r[i+1] = (r[i]+a[i]) % k; }

  ll ans = 0;
  map<int,int> mp;
  queue<int> q;
  rep(i,n+1){
    ans += mp[r[i]];

    mp[r[i]]++;
    q.push(r[i]);
    if(q.size()==k){
      mp[q.front()]--;
      q.pop();
    }
  }

  cout << ans << endl;
  return 0;
}
