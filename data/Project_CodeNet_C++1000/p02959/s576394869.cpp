#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> monster(N + 1);
  vector<int64_t> hero(N);
  for(int i = 0; i < N + 1; i++) {
    cin >> monster.at(i);
  }
  for(int i = 0; i < N; i++) {
    cin >> hero.at(i);
  }
  int64_t ans = 0;
  for(int i = 0; i < N; i++) {
    if(monster.at(i) >= hero.at(i)) {
      ans += hero.at(i);
      continue;
    }
    else if(hero.at(i) < monster.at(i) + monster.at(i + 1)) {
      ans += hero.at(i);
      monster.at(i + 1) -= hero.at(i) - monster.at(i);
    }
    else {
      ans += monster.at(i) + monster.at(i + 1);
      monster.at(i + 1) = 0;
    }
  }
  cout << ans << endl;
}