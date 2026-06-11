#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

typedef std::pair<int, int> ii;

int H, W, M;
int SH[300005];
int SW[300005];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> H >> W >> M;
  for (int i = 0; i < H; ++i)
    SH[i] = 0;
  for (int j = 0; j < W; ++j)
    SW[j] = 0;
  std::set<ii> targets;
  for (int i = 0; i < M; ++i) {
    int h, w; std::cin >> h >> w;
    h--;  w--;
    SH[h]++;
    SW[w]++;
    targets.insert({h, w});
  }

  std::vector<ii> SSH, SSW;
  for (int h = 0; h < H; ++h)
    SSH.push_back({SH[h], h});
  for (int w = 0; w < W; ++w)
    SSW.push_back({SW[w], w});
  std::sort(SSH.begin(), SSH.end());
  std::sort(SSW.begin(), SSW.end());

  int max_ans = SSH[H-1].first + SSW[W-1].first;
  int ans = 0;
  for (int i = H-1; i >= 0; --i) {
    if (max_ans - (SSH[i].first + SSW[W-1].first) >= 2) break;
    for (int j = W-1; j >= 0; --j) {
      if (max_ans - (SSH[i].first + SSW[j].first) >= 2) break;
      int cnt = SSH[i].first + SSW[j].first;
      if (cnt <= ans) break;
      if (targets.find({SSH[i].second, SSW[j].second}) != targets.end())
        cnt--;
      //std::cout << SSH[i].first << "+" << SSW[j].first << "-" << int(targets.find({SSH[i].second, SSW[j].second}) != targets.end()) << "=" << cnt << "\n";
      ans = std::max(ans, cnt);
    }
  }

  std::cout << ans << "\n";

  return 0;
}
