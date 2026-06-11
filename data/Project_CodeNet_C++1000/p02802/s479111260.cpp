#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> V(N);
  int ac = 0, pe = 0;
  for (int i = 0; i < M; i++) {
    int p;
    string S;
    cin >> p >> S;
    if (V.at(--p) == -1) continue;
    if (S == "WA") V.at(p)++;
    else ac++, pe += V.at(p), V.at(p) = -1;
  }
  cout << ac << " " << pe << "\n";
}