#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<int> p(M, 0);
  vector<bool> S(M, 0);
  vector<int> penalty(N, 0);
  vector<bool> status(N, false);
  rep(i, M) {
    string temp = "";
    cin >> p[i] >> temp;
    p[i]--;
    if (temp == "AC") {
      S[i] = true;
    } else {
      S[i] = false;
    }
  }

  int ac = 0;
  int sum_penalty = 0;
  rep(i, M) {
    if (S[i] && !(status[p[i]])) { // 未ACでACした
      status[p[i]] = true;
      sum_penalty += penalty[p[i]];
      ac++;
    } else if (S[i] && status[p[i]]) { // 既ACでACした
      continue;
    } else if (!(S[i]) && !(status[p[i]])) { // 未ACでWAした
      penalty[p[i]]++;
    } else if (!(S[i]) && status[p[i]]) { // 既ACでWAした
      continue;
    }
  }

  cout << ac << " " << sum_penalty << endl;
}