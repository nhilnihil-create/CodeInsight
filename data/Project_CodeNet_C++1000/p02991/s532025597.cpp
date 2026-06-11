#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
#define pb push_back
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;


int main(){
  int n, m;
  cin >> n >> m;
  vector<int> e[n];
  int d[n][3];
  rep(i, n) fill(d[i], d[i] + 3, INF);
  rep(i, m){
    int u, v;
    cin >> u >> v;
    u--; v--;
    e[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--;t--;
  d[s][0] = 0;
  bool checked[n][3];
  rep(i, n) fill(checked[i], checked[i] + 3, false);
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int from = q.front();
    q.pop();
    for(int x : e[from]){
      if(checked[x][1] && d[x][1] <= d[from][0] + 1) continue;
      checked[x][1] = true;
      d[x][1] = min(d[from][0] + 1, d[x][1]);
      for(int y : e[x]){
        if(checked[y][2] && d[y][2] <= d[from][0] + 1) continue;
        checked[y][2] = true;
        d[y][2] = min(d[from][0] + 1, d[y][2]);
        for(int z : e[y]){
          if(checked[z][0] && d[z][0] <= d[from][0] + 1) continue;
          d[z][0] = min(d[from][0] + 1, d[z][0]);
          checked[z][0] = true;
          q.push(z);
        }
      }
    }
  }
  if(d[t][0] == INF) d[t][0] = -1;
  cout << d[t][0] << endl;
}
                    