#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
ll k;
vector<ll> t;


bool ok(ll x){
  ll sb = 0;
  vector<ll> sq;
  for(ll i = 0 ; i < n; i ++ ){
    if(t[i] % x == 0) continue;
    sb += x-(t[i]%x);
    sq.push_back((t[i]%x)-(x-(t[i]%x)));
  }
  sort(sq.begin(), sq.end());
  if(sb%x != 0) return false;
  ll m = sb/x;
  for(int i = 0 ; i < m; i ++ ){
    if(i >= (ll)sq.size()) break;
    sb += sq[i];
  }
  sb /= 2ll;
  if(sb <= k) return true;
  return false;
}

int main(){
  fastIO;
  cin >> n >> k; 
  t.resize(n);
  ll sum = 0;
  for(int i = 0 ; i < n; i ++ ){
    cin >> t[i];
    sum += t[i];
  }
  ll ans = 1;
  for(ll i = 1; i * i <= sum; i ++ ){
    if(sum % i == 0){
      if(ok(i)) ans = max(ans, i);
      if(ok(sum/i)) ans = max(ans,sum/i);
    }
  }
  cout << ans << "\n";
  return 0;
}