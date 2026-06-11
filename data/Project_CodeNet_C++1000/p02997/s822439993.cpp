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

int main(){
  int N, K; cin >> N >> K;

  if (K > (N - 1) * (N - 2) / 2){
    cout << -1 << endl;
    return 0;
  }

  vector <Pii> ans;
  for (int i = 2; i <= N; i++){
    ans.push_back({1, i});
  }

  int cnt = (N - 1) * (N - 2) / 2;
  for (int i = 2; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      if (cnt == K) break;
      ans.push_back({i, j});
      cnt--;
    }
    if (cnt == K) break;
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i].fi << " " << ans[i].se << endl;
  }

  return 0;
}
