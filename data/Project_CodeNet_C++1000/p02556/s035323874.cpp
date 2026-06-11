#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N; cin >> N;
  vector<long long> z, w;
  for(int i = 0; i < N; i++){  
    int x, y; cin >> x >> y;
    z.push_back(x+y);
    w.push_back(x-y);
  }
  sort(z.begin(), z.end());
  sort(w.begin(), w.end());
  cout << max(z[N-1] - z[0], w[N-1] - w[0]) <<endl;
}
