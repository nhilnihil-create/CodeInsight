#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N;
  cin >> N;
  int res = 0;
  vector<vector<int>> num(10, vector<int>(10, 0));
  for (int n=1; n<=N; n++) {
    vector<int> d;
    int nn = n;
    while (nn) {
      d.push_back(nn%10);
      nn /= 10;
    }
    int a = d[0], b = d.back();
    if (!a||!b) continue;
    num[a][b]++;
  }
  for (int a=1; a<10; a++) {
    for (int b=1; b<10; b++) res += num[a][b]*num[b][a];
  }
  cout << res << endl;
  return 0;
}