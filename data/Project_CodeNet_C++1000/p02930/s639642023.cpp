#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N;
bool color[505][505], visited[505][505];
int ans[505][505];

int edge;
int DFS(int level, int now){
  if (visited[level][now]) return 0;
  visited[level][now] = true;
  for (int i = now + 1; i < N; i++){
    if (ans[now][i] > 0) continue;
    if (color[level][now]) color[level][i] = false;
    else color[level][i] = true;
    DFS(level, i);
    return 0;
  }

  for (int i = edge; i < N; i++){
    if (visited[level][i]) {
      edge++; continue;
    }

    DFS(level, edge);
  }
  
  return 0;
}

int Solve(int level){
  vector <int> Black, White;
  for (int i = 0; i < N; i++){
    if (!visited[level][i]) continue;
    if (color[level][i]) Black.push_back(i);
    else White.push_back(i);
  }

  for (int i = 0; i < Black.size(); i++){
    for (int j = 0; j < White.size(); j++){
      int B = Black[i], W = White[j];
      if (B > W) swap(B, W);
      if (ans[B][W] == 0) ans[B][W] = level;
    }
  }
  return 0;
}

int main(){
  cin >> N;

  int start = 0;
  for (int level = 1; level <= N; level++){
    bool flag = true;
    for (int i = start; i < N; i++){
      edge = i;
      for (int j = i + 1; j < N; j++){
        if (ans[i][j] == 0) flag = false;
      }
      if (flag) {
        start++; continue;
      }
      DFS(level, i); Solve(level);
      break;
    }
  }


  for (int i = 0; i < N - 1; i++){
    cout << ans[i][i+1];
    for (int j = i + 2; j < N; j++){
      cout << " " << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
