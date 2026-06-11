#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;

  vector<int> Front;
  int cnt = 0;
  rep(i, N) {
    if (S[i] == 'o' && cnt < K) {
      Front.emplace_back(i);
      ++cnt;
      i += C;
    }
  }

  vector<int> Back;
  cnt = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == 'o' && cnt < K) {
      Back.emplace_back(i);
      ++cnt;
      i -= C;
    }
  }
  reverse(Back.begin(), Back.end());

  rep(i, K) {
    if (Front[i] == Back[i]) cout << Front[i] + 1 << endl;
  }
  return 0;
}
