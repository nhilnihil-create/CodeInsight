#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M, H[100010];
vector<int> G[100010];

int main(){
  cin >> N >> M;
  rep(i, N) cin >> H[i];
  rep(i, M){
    int a, b;
    cin >> a >> b;
    // aとbは0インデックスに揃える
    a--;
    b--;
    G[a].push_back(b);
    // 無向グラフなのでbにもaを追加する
    G[b].push_back(a);
  }
  int ans = 0;
  rep(i, N){
    bool check = true;
    for (auto g : G[i]){
      if (H[i] <= H[g]) check = false;
    }
    if (check) ans++;
  }
  cout << ans << endl;
}
