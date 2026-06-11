#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646;
const double pi = 3.141592653589793;



int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int v;
  int max_col = 0;
  vector< vector<pii> > adj(200001);

  cin >> v;
  int color[200001] = {};
  queue< pair<int, int> > q;
  for(int i = 0 ; i < v - 1 ; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(mp(b,i));
  }
  q.push(mp(1, 0));

  while(!q.empty()) {
    int p_color = q.front().second;
    int cur = q.front().first;
    q.pop();
    set<int> c;
    c.insert(p_color);
    int s_color = 1;
    for(int i = 0 ; i < adj[cur].size() ; i++) {
      int nxt = adj[cur][i].first;
      int idx = adj[cur][i].second;
      if(s_color == p_color) {
        s_color++;
      }
      color[idx] = s_color;
      q.push(mp(nxt, s_color));
      max_col = max(max_col, s_color);
      s_color++;
    }
  }

  cout << max_col << endl;
  for(int i = 0 ; i < v - 1 ; i++) {
    cout << color[i] << endl;
  }
} 