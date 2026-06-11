#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, K;
  cin >> N >> K;
  if (K==1) cout << 0 << endl;
  else cout << N-K << endl;
}