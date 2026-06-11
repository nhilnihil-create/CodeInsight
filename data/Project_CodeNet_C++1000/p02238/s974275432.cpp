#include <iostream>
using namespace std;

const int N = 100;
int M[N][N];
int n;
int t;
int color[N];
int d[N], f[N];

void init(){
  for(int i=0;i<n;i++){
    color[i] = 0;
  }
}

void dfs(int x){
  color[x] = 1;
  d[x] = ++t;
  for(int i=0;i<n;i++){
    if(M[x][i] == 1 && color[i] == 0){
      dfs(i);
    }
  }
  color[x] = 2;
  f[x] = ++t;
}

int main(){
  cin >> n;
  int u, k, v;
  for(int i=0;i<n;i++){
    cin >> u >> k;
    for(int j=0;j<k;j++){
      cin >> v;
      M[u-1][v-1] = 1;
    }
  }
  init();
  for(int i=0;i<n;i++)
    if(color[i] == 0) dfs(i);
  for(int i=0;i<n;i++){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
  return 0;
}

