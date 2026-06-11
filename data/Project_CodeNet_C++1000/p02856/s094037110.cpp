#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 9;
ll d[N], c[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  ll len = 0, sum = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> d[i] >> c[i];
    sum += d[i] * c[i];
    len += c[i];
  }
  ll ans = len - 1;
  if(sum >= 9)
    ans += (sum - 1) / 9;
  cout << ans << "\n";
  return 0;
}