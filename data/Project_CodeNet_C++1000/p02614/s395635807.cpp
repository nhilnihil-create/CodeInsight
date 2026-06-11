#include <bits/stdc++.h>
using namespace std;
char g[10][10];
int h,w;
int getbit(int x,int pos){
    return (x >> pos) & 1;
}
int fun(int row,int col){
    int cnt = 0;
    for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
        if(g[i][j] == '#'){
            if(getbit(row,i) == 0 && getbit(col,j) == 0 ){
                cnt++;
            }
        }
    }
  }

    return cnt;
}
int main() {
  int k,ans = 0;
  cin >> h >> w >> k;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
        cin >> g[i][j];
    }
  }
  for(int i = 0; i < (1 << h); i++){
    for(int j = 0; j < (1 << w); j++){
        if(fun(i,j) == k)
            ans++;
    }
  }
    cout << ans << endl;
  return 0;
}