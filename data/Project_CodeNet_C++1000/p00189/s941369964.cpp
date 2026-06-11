#include <iostream>

using namespace std;
int a, b, c, i, j, s, n, mi,  d[10][10], cost[10];

void dic(int ans[]) {
  for(s = 0; s < 10; s++) {
    for(i = 0; i < 10;i++) cost[i] = 100000000;
    int sum = 0, f[10] = {};
    cost[s] = 0;
    mi = s;
    for(i = 0; i < 10; i++) {
      f[mi] = 1;
      for(j = 0; j < 10; j++)  if(!f[j] && cost[j] > cost[mi] + d[mi][j]) cost[j] = cost[mi] + d[mi][j];
      int min = 200000000;
      for(j = 0; j < 10; j++)  if(!f[j] && min > cost[j])  min = cost[mi = j];
    }
    for(i = 0; i < 10; i++)  if(cost[i] != 100000000) sum += cost[i];
    //    cout << sum << endl;
    if(ans[1] > sum && sum != 0){
      ans[0] = s;
      ans[1] = sum;
    }
  }
}


int main() {
  while(cin >> n, n != 0) {
    for(i = 0; i < 10; i++)
      for(j = 0; j < 10; j++)  d[i][j] = 100000000;
    while(n--) {
      cin >> a >> b >> c;
      d[a][b] = d[b][a] = c;
    }
    int ans[2] = {100000000, 100000000};
    dic(ans);
    cout << ans[0] << ' ' << ans[1] << endl;
  }
  return 0;
}