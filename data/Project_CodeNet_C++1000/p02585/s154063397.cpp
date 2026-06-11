//内容さっきと同じだけどatcoder problemsの反映がおかしかったので。
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  int64_t M_score = -2000000000LL;
  scanf("%d %d", &n, &k);
  vector<int> p(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for(int i = 1; i <= n; i++) {
    int move = 0, masu = i;//開始時
    int64_t sum = 0LL, sub_max = -20000000000LL;
    vector<int64_t> v;//添え字ずれます
    bool syukai = false;
    while(move < k) {
      move++;
      masu = p[masu];
      sum += c[masu];
      v.push_back(sum);
      sub_max = max(sub_max, sum);
      if(masu == i) {
        syukai = true;
        break;
      }
    }
    //この段階でsyukai == trueならsumは一周して得られるscore
    if(syukai && sum > 0) {
      for(int j = 0; j < move; j++) {
        M_score = max(M_score, v[j] + sum * (int64_t)((k - (j + 1)) / move));
      }
    }else {
      M_score = max(M_score, sub_max);
    }
  }
  cout << M_score;
}
