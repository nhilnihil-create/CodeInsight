#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
  constexpr char OPPONENT_HAND[] = "spr";
  constexpr int NUMBER_OF_HANDS = 3;

  int N, K;
  cin >> N >> K;

  int point[NUMBER_OF_HANDS];
  for (int i = 0; i < NUMBER_OF_HANDS; i++) cin >> point[i];

  string T;
  cin >> T;

  int ans = 0;
  deque<bool> skipped(N, false);

  for (int round = 0; round < N; round++) {
    if (round >= K && T[round] == T[round - K] && skipped[round - K] == false) {
      skipped[round] = true;
      continue;
    }
    for (int idx = 0; idx < NUMBER_OF_HANDS; idx++) {
      if (T[round] == OPPONENT_HAND[idx]) {
        ans += point[idx];
      }
    }
  }

  cout << ans << endl;
}