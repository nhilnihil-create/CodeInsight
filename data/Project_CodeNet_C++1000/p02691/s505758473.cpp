#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  // |i-j| = Xi + Xj
  // i < j, Xi + i = j - Xj

  map<ll, ll> m;

  int N; cin >> N;
  ll ans  = 0;

  for(ll i = 0; i < N; i++){
    ll now; cin >> now;
    ans += m[i - now];

    m[i+now]++;
  }
  cout << ans << endl;
}
