#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int INF = 1000000;
  
  int hp, N;
  std::vector<int> dmg;
  std::vector<int> mp;

  cin >> hp >> N;
  for (int i=0; i < N; ++i) {
    int d, m;
    cin >> d >> m;
    dmg.push_back(d);
    mp.push_back(m);
  }

  std::vector<int> solution;
  solution.push_back(0);
  int max_dmg = *max_element(dmg.begin(), dmg.end());

  for (int i = 1; i <= hp + max_dmg; ++i) {
    std::vector<int> mps;

    for (int j = 0; j < N; ++j) {
      if (i - dmg[j] == INF)
        continue;
      if (solution[i - dmg[j]] < 0)
        continue;
      mps.push_back(solution[i - dmg[j]] + mp[j]);
    }

    if (mps.size() == 0) {
      solution.push_back(INF);
    } else {
      solution.push_back(*min_element(mps.begin(), mps.end()));
    }
  }

  cout << *min_element(solution.begin() + hp, solution.end()) << endl;
  return 0;
}
