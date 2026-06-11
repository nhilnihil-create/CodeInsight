#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

vector<int> Zalgo(string &S) {
  int N = S.size();
  vector<int> Z(N, 0);

  Z[0] = N;
  int i = 1, j = 0;
  while (i < N) {
    while (i + j < N && S[j] == S[i + j]) j++;
    Z[i] = j;

    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (k < j && k + Z[k] < j) {
      Z[i + k] = Z[k];
      k++;
    }
    i += k;
    j -= k;
  }
  int ret = 0;
  for (int i = 1; i < N; ++i) {
    ret = max(ret, Z[i]);
  }
  return Z;
}

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  string S;
  cin >> S;

  int answer = 0;
  rep(i, N - 1) {
    string T = S.substr(i, N - i);
    auto lcp = Zalgo(T);
    for (int j = 0; j < (N - i); ++j) {
      int l = min(lcp[j], j);
      answer = max(answer, l);
    }
  }
  cout << answer << endl;
  return 0;
}
