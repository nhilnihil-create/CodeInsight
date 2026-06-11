#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;

vector<int> d[200010];

int main(){
  int n, m;
  cin >> n >> m;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    --a;
    d[a].push_back(b);
  }
  int ans = 0;
  priority_queue<int> q;
  rep(i, m) {
    if (d[i].size()) rep(j, d[i].size()) q.push(d[i][j]);
    if (!q.size()) continue; 
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
}

