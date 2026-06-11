
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int n; 
int main() {
  cin >> n;
  vector<P> time(n);
  rep(i,n) {
    int a,b; cin >> a >> b;
    if (a > b) {
      cout << "No" << endl;
      return 0;
    }
    time[i] = make_pair(b,a);
  }
  sort(time.begin(), time.end()); //(end, start)
  bool can = true;
  int end = 0;
  rep(i,n) {
    end += time[i].second;
    if (end > time[i].first) can = false;
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}