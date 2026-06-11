#include <iostream>

using namespace std;

int main(){
  int n; cin >> n;
  //adjacent matrix expression
  int a[n+1][n+1];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      a[i][j]=0;
    }
  }
  for(int i=0;i<n;i++){
    int u; cin >> u;
    int k; cin >> k;
    for(int i=0;i<k;i++){
      int v; cin >> v;
      a[u][v]=1;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-1;j++){
      cout << a[i][j] << " ";
    }
    cout << a[i][n] << endl;
  }
}