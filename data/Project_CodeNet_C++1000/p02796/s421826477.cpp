#include <bits/stdc++.h>
using namespace std;

int main(void){
  // Keyence2020 B Robot Arms
  int n, x, l, ans, cur, i;
  scanf("%d", &n);
  vector<pair<int, int>> ps(n);
  for (i = 0; i < n; i++){
    scanf("%d %d", &x, &l);
    ps[i] = {x + l, x - l};
  }

  sort(ps.begin(), ps.end());
  ans = n, cur = ps[0].first;
  for (i = 1; i < n; i++)
    if (ps[i].second < cur)
      --ans;
    else
      cur = ps[i].first;

  printf("%d\n", ans);

  return 0;
}
