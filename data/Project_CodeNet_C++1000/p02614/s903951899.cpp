#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W, K; cin>>H>>W>>K;
  string mat[H];
  for(int i = 0; i < H; ++i) {
    cin>>mat[i];
  }
  int n = 1<<(H + W);
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int row = i >> W; int col = i & ((1 <<W) - 1);
    int cnt = 0;
    for(int j = 0; j < H; ++j) {
      for(int k  = 0; k < W; ++k) {
        if((1 << j) & row) continue;
        if((1 << k) & col) continue;
        if(mat[j][k] == '#') ++cnt;
      }
    }
    if(cnt == K) ++ans;
  }
  cout<<ans<<endl;
  return 0;
}