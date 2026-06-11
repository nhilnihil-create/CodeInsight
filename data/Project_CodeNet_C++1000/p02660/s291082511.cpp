#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll N;
vector <ll> P;
int cnt[100];

int Solve(){
  ll now = N;
  for (ll i = 2; i * i <= N; i++){
    int ans = 0;
    while (now % i == 0){
      now /= i; ans++;
    }
    P.push_back(ans);
  }
  if (now > 1) P.push_back(1);

  return 0;
}

int main(){
  cin >> N;
  for (int i = 1; i < 100; i++){
    cnt[i] = cnt[i-1] + i;
  }
  Solve();
  int ans = 0;
  for (int i = 0; i < P.size(); i++){
    for (int j = 1; j < 100; j++){
      if (P[i] < cnt[j]){
        ans += j - 1; break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
