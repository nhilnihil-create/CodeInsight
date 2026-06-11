#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int main() {
  int N;
  string S, T;
  cin >> N >> S >>T;

  rep (i, N) {
    cout << S[i] << T[i];
  }
  cout << endl;

  return 0;
}