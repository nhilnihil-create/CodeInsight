#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int len = S.size();

  rep (i, len) {
    int x = S[i] - 'A';
    x = (x + N) % 26;
    putchar('A' + x);
  }
  cout << endl;

  return 0;
}