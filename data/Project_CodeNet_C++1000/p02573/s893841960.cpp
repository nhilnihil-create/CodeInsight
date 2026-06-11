#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int par[1000000];

void init(int n) {
  rep(i, n+1) par[i] = i;
}

int root(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = root(par[x]);
  }
}

bool same(int x, int y) {
  return root(x) == root(y);
}

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
  
  par[x] = y;
}

int main()
{
  int N, M;
  cin >> N >> M;

  init(N);

  rep(i, M)
  {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    
    if (!same(A, B)) {
      unite(A, B);
    }
  }

  vector<int> count(N, 0);
  int mx = 0;
  rep(i, N) {
    count[root(i)]++;
  }
  rep(i, N) {
    mx = std::max(mx, count[root(i)]);
  }

  cout << mx << endl;

  return 0;
}
