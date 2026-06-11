#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int MAX_N = 100000;
const int MAX_V = 1000000000;

int N;
vector<int> X(MAX_N);
vector<int> L(MAX_N);
  
int main() {
  int n; cin >> n;
  vector<int> x(n);
  vector<int> len(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> len[i];
  
  vector<pair<int, int>> ran(n);
  for (int i = 0; i < n; i++) {
    ran[i].first = x[i] + len[i];
    ran[i].second = x[i] - len[i];
  }
  
  sort(ran.begin(), ran.end());
  
  int ans = 0;
  int cur = -MAX_V;
  for (int i = 0; i < n; i++) {
    if (cur <= ran[i].second) {
      ans++;
      cur = ran[i].first;
    }
  }
  
  cout << ans << endl;
}