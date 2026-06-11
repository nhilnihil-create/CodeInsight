#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> cmp(n);
  rep(i, n) {
    cin >> p[i];
    cmp[i] = p[i];
  }
  sort(p.begin(), p.end());
  int cnt = 0;
  rep(i, n) {
    if(cmp[i] != p[i]) cnt++;
  }
  bool flag = false;
  if(cnt <= 2) flag = true;
  
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
  