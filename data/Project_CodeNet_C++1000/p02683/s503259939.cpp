#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n, m, x;
  cin >> n >> m >> x;

  vector<ll> cost(n);
  vector<vector<ll>> a(n);

  rep (i,n) {
    cin >> cost[i];
    rep (j,m) {
      int tmp;
      cin >> tmp;
      a[i].push_back(tmp);
    }
  }

  vector<ll> tot(m);
  rep (i,n) {
    rep (j,m) {
      tot[j] += a[i][j];
    }
  }
  rep (i,m) {
    if (tot[i] < x) {
      cout << -1 << endl;
      return 0;
    }
  }

  ll result = LLINF;

  for (int bit = 0; bit < pow(2, n); bit++) {
    // 今回選択する参考書リスト
    vector<int> book;
    int tbit = bit;

    // 参考書リストの作成
    int count = 0;
    while (tbit > 0) {
      if (tbit & 1) {
        book.push_back(count);
      }
      count++;
      tbit >>= 1;
    }

    // 選び方の時に、理解度の累計を計算
    ll tcost = 0;
    vector<int> score(m);
    for (int b : book) {
      rep (i,m) {
        score[i] += a[b][i];
      }
      tcost += cost[b];
    }

    // x以上かを判定
    bool isOk = true;
    rep (i,m) {
      if (score[i] < x) isOk = false;
    }

    // 更新
    if (isOk)  result = min(result, tcost);
  }

  cout << result << endl;
}


