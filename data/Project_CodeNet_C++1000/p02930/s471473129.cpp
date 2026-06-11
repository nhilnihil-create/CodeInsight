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

int N, ans[505][505];

bool visited[505], color[505];


int DFS(int start, int level){
  if (visited[start]) return 0;
  visited[start] = true;

  for (int i = start + 1; i < N; i++){
    if (ans[start][i] == 0 && !visited[i]){
      if (color[start]) color[i] = false;
      else color[i] = true;
      DFS(i, level);
    }
  }


  for (int i = 0; i < N; i++){
    if (!visited[i]){
      DFS(i, level);
    }
  }

  return 0;
}


int main(){
  cin >> N;
  for (int L = 1; L <= N; L++){
    fill(visited, visited+ N, false);
    bool flag = false;
    int start = 0;
    for (int i = 0; i < N; i++){
      for (int j = i + 1; j < N; j++){
        if (ans[i][j] == 0){
          flag = true;
          start = i;
          DFS(i, L);
          break;
        }
      }
      if (flag) break;
    }

    if (!flag) break;

    for (int i = 0; i < N; i++){
      for (int j = i + 1; j < N; j++){
        if (ans[i][j] != 0) continue;
        if (color[i] != color[j]){
          ans[i][j] = L;
        }
      }
    }
  }

  for (int i = 0; i < N-1; i++){
    cout << ans[i][i+1];
    for (int j = i + 2; j < N; j++){
      cout << " " << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
