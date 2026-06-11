#include <iostream>
// #include <vector>
using namespace std;

const int MAX = 100;
const int INFTY = (1 << 21);
int n;
int M[MAX][MAX];

void dijkstra(int s){
  int color[MAX], d[MAX], p[MAX];
  // vector<int> S;
  for(int i=0;i<n;i++){
    color[i] = 0;
    d[i] = INFTY;
    p[i] = -1;
  }
  d[s] = 0;
  p[s] = -1;
  color[0] = 1;

  while(true){
    int mincost = INFTY;
    int u = -1;
    for(int i=0;i<n;i++){
      if(color[i] != 2 && d[i] < mincost){
        mincost = d[i];
        u = i;
      }
    }

    // if(mincost == INFTY) break;
    if(u == -1) break;
    color[u] = 2;

    // S.push_back(u);
    for(int i=0;i<n;i++){
      if(M[u][i] != -1 && (d[i] > M[u][i] + d[u])){
        d[i] = M[u][i] + d[u];
        color[i] = 1;
        p[i] = u;
      }
    }
  }

  for(int i=0;i<n;i++){
    cout << i << " " << d[i] << endl;
  }
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      M[i][j] = INFTY;

  for(int i=0;i<n;i++){
    int id, k, v, c;
    cin >> id >> k;
    for(int j=0;j<k;j++){
      cin >> v >> c;
      M[id][v] = c;
    }
  }

  dijkstra(0);
  return 0;
}

