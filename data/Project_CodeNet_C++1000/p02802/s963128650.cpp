#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ac(n);
  vector<int> wa(n);
  int t_ac = 0;
  int t_wa = 0;
  rep(i, m) {
    int p; string s;
    cin >> p >> s;
    p--;
    if(s == "AC") {
      ac[p]++;
      if(ac[p] > 1) continue;
      t_wa += wa[p];
    } else {
      wa[p]++;
    }
  }
  rep(i, n) {
    if(ac[i] >=1) t_ac++;
  }
  cout << t_ac << " " << t_wa << endl;
  return 0;
}