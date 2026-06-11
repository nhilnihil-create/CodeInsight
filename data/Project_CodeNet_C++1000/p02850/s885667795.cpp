#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}

vector<vector<int>> p(100005, vector<int>(0));
vector<int> v(100005, -1);
map<string, int> col;
void dfs(int x) {
  int y = p[x].size();
  for (int i = 0; i < y; i++) {
    string s = to_string(min(x, p[x][i]));
    string ss = to_string(max(x, p[x][i]));
    string sss = s + "#" + ss;
    if (col[sss] == 0)  {
      if (v[p[x][i]] == -1) {
        v[p[x][i]] = (v[x] + 1);
      }
      v[x] = v[p[x][i]];
      
      col[sss] = v[x];
      
      dfs(p[x][i]);
    }
  }
  return;
}
  
int main() {
  int n;
  cin >> n;
  vector<string> pa(n-1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    p[a].push_back(b);
    p[b].push_back(a);
    string S = to_string(min(a, b));
    string SS = to_string(max(a, b));
    string SSS = S + "#" + SS;
    pa[i] = SSS;
  }
  int count = p[0].size();
  for (int i = 1; i < n; i++) {
    int P = p[i].size();
    count = max(count, P);
  }
  cout << count <<endl;
  v[0] = 0;
  dfs(0);
  for (int i = 0; i < n -1; i++) {
    int cc = col.at(pa[i]) % count;
    if (cc == 0) {
      cc = count;
    }
    cout << cc <<endl;
  }
} 
