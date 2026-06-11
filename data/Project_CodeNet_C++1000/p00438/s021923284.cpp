#include <iostream>
#include <algorithm>

using namespace std;

bool data[16][16];
int ans;
int a, b;
int dx[] = {0, 1};
int dy[] = {1, 0};

void dfs(int y, int x){
  if(y == b-1 && x == a-1){
    ans++;
    return;
  }
  for(int i=0;i<2;i++){
    int ty = y + dy[i];
    int tx = x + dx[i];
    if(ty<0 || ty>=b) continue;
    if(tx<0 || tx>=a) continue;
    if(data[ty][tx]) dfs(ty, tx);
  }
}

main(){
  int n;
  while(cin >> a >> b){
    if(a == 0 && b == 0) break;
    cin >> n;
    fill(data[0], data[16], true);
    for(int i=0;i<n;i++){
      int in1, in2;
      cin >> in1 >> in2;
      data[in2-1][in1-1] = false;
    }
    ans = 0;
    dfs(0, 0);
    cout << ans << endl;
  }
  return 0;
}