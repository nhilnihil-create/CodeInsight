#include <iostream>
#include <algorithm>
using namespace std;

int d[11][11];

void init(){
  for(int i = 0; i < 11; i++){
    for(int j = 0; j < 11; j++){
      if(i == j) d[i][j] = 0;
      else d[i][j] = 1e9;
    }
  }
}

int main(void){
  int n;
  while(true){
    cin >> n;
    if(!n) break;
    int a, b, c, m = 0;
    init();

    for(int i = 0; i < n; i++){
      cin >> a >> b >> c;
      d[a][b] = c;
      d[b][a] = c;
      m = max(max(m, a), b);
    }

    for(int k = 0; k <= m; k++){
      for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }

    int town, mincost = 1e9;

    for(int i = 0; i <= m; i++){
      int sum = 0;
      for(int j = 0; j <= m; j++){
        sum += d[i][j];
      }
      if(sum < mincost){
        town = i;
        mincost = sum;
      }
    }

    cout << town << " " << mincost << endl;
  }
  return 0;
}