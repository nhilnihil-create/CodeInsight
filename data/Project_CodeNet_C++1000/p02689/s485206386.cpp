#include <iostream>
#include <vector>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];
int isVisited[1 + NMAX];

vector <int> adj[1 + NMAX];

int main() {

  int n, m, a, b, ans = 0;
  bool good = true;
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    cin >> v[i];
  }
  for(int i = 1;i <= m;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 1;i <= n;i++){
    if(isVisited[i] == false){
      isVisited[i] = true;
      good = true;

      for(int j = 0;j < adj[i].size();j++){

        if(v[i] > v[adj[i][j]]){
          isVisited[adj[i][j]] = true;
        }else{
          good = false;
        }
      }
      if(good){
        ans++;
      }
    }

  }
  cout << ans;
  return 0;
}
