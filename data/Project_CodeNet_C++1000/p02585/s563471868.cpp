#include <bits/stdc++.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define POS(x) ((x) > 0 ? (x) : 0)
using namespace std;

const int ARR_SIZE = 5e3+5;

int P[ARR_SIZE];
long long C[ARR_SIZE];

int parent[ARR_SIZE];

int Find(int x) {
  if (parent[x] == -1) {
    return x;
  }
  return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  int px = Find(x), py = Find(y);
  if (px != py) {
    parent[py] = px;
  }
}



int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  memset(parent, -1, sizeof(parent));

  for (int i = 1; i <= n; ++i) {
    scanf("%d", P+i);
    Union(i, P[i]);
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", C+i);
  }

  // from parent to scores
  unordered_map<int, long long> ringScore;
  unordered_map<int, int> ringSize;
  for (int i = 1; i <= n; ++i) {
    ringScore[Find(i)] += C[i];
    ringSize[Find(i)]++;
  }

  long long ans = LONG_LONG_MIN;

  for (int i = 1; i <= n; ++i) {
    int j = P[i], nMove = 0, rSize = ringSize[Find(i)];
    long long tot = 0, rScore = POS(ringScore[Find(i)]);
    
    if (k >= rSize) {
      ans = max(ans, (k-nMove)/rSize*ringScore[Find(i)]);
    }

    while (j != i) {
      tot += C[j];
      nMove++;
      
      ans = max(ans, tot + (k-nMove)/rSize*rScore);
      if (nMove >= k) break;
      j = P[j];
    }
  }
  printf("%lld\n", ans);



  return 0;
}