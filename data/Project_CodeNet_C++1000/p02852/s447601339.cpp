#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1145141919;
const int N = 100000;

int n, m;
string s;

vector<int> cl0;
vector<int> rol;

int main() {
  cin >> n >> m >> s;
  rep(i, n+1) if (s[i] == '0') cl0.push_back(i);
  int x = n;
  while (x > 0) {
    int nx = *lower_bound(cl0.begin(), cl0.end(), x-m);
    if (nx >= x) {
      cout << -1 << endl;
      return 0;
    }
    rol.push_back(x - nx);
    x = nx;
  }
  reverse(rol.begin(), rol.end());
  rep(i, rol.size()) {
    printf("%d", rol[i]);
    if (i == rol.size()-1) printf("\n");
    else printf(" ");
  }
  return 0;
}