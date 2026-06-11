#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fill(x, y) memset(x, y, sizeof(x))
#define MOD 1000000007
#define NUM 100  // 200000

using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  // xとyの木を統合. （x,yのそれぞれの根の内、値が小さいほうに統合される）
  // 例：root(x) = 1, root(y) == 5　なら root(y) = 1　になる
  bool unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
      return false;
    } else {
      if (rx > ry) swap(rx, ry);
      par[ry] = rx;
    }
    return true;
  }

  bool isSame(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  //根確認用
  // for (int i = 0; i < N; i++)
  // cout << "UF.par[" << i << "] = " << UF.par[i] << endl;
};

/*最も人数の多い友達グループの人数がそのまま答えとなる*/
int main(void) {
  int N, M;
  cin >> N >> M;

  UnionFind UF(N);  //友達集合を作成（最初はそれぞれの根は自分自身）
  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    UF.unite(A - 1, B - 1);
  }

  vector<int> cnt(N, 0);
  int max = 0;
  for (int i = 0; i < N; i++) {
    cnt[UF.root(UF.par[i])]++;
  }
  for (int i = 0; i < N; i++) {
    if (max < cnt[i]) {
      max = cnt[i];
    }
  }

  cout << max << endl;
  return 0;
}
