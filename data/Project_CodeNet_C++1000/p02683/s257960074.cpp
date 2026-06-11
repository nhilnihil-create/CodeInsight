#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define INF 1001001001

using namespace std;

int main(void){
  int n,m,x,ans=INF;
  int c[15], a[15][15];
  
  cin >> n >> m >> x;
  for (int i=0; i<n; i++){
    int t; cin >> t;
    c[i] = t;
    for (int j=0; j<m; j++){
      cin >> t;
      a[i][j] = t;
    }
  }
  
  for (unsigned int b=0; b<1<<n; b++){
    int flg=1, cost=0;
    int skl[15] = {0};
    for (int i=0; i<n; i++){
      if (((1<<i) & b) == 0) continue; 
//      cout << i ;
      cost += c[i];
      for (int j=0; j<m; j++){
        skl[j] += a[i][j];
      }
    }
    for (int i=0; i<m; i++){
      if (skl[i]<x) flg=0;
    }
//    cout << b << " " << flg << " " << cost << endl;
    if (flg) ans = MIN(ans, cost);
  }
  cout << (ans==INF?-1:ans) << endl;
  return 0;
}