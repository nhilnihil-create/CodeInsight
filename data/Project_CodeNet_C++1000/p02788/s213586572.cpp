#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const ll INF = 1e9 + 1e6 + 1e3 + 1;


int main(){
  ll n, d, a;
  cin >> n >> d >> a;
  P monster[200200];
  rep(i, n){
    ll x, h;
    cin >> x >> h;
    monster[i] = P(x, h);
  }
  sort(monster, monster + n);
  ll hp[200200], x[200200];
  fill(x, x + 200200, INF);
  rep(i, n){
    hp[i] = (monster[i].second + a - 1) / a;
    x[i] = monster[i].first;
  }
  ll ans = 0;
  ll damage[200200];
  int pos = 0;
  fill(damage, damage + 200200, 0);
  for(int i = 0; i < n; i++){
    while(pos < i){
      pos++;
      damage[pos] += damage[pos-1];
      hp[pos] += damage[pos];
    }
    if(hp[i] <= 0) continue;
    ans += hp[i];

    damage[i] -= hp[i];
    int idx = lower_bound(&x[i], x + n, x[i] + 2*d+1) - x;
    damage[idx] += hp[i];
  }
  cout << ans << endl;
}