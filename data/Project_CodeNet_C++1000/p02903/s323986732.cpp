#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int H,W,A,B; cin >> H >> W >> A >> B;

  int ans[H][W];

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(i < H-B){
        if(j < A){
          ans[i][j] = 0;
        } else {
          ans[i][j] = 1;
        }
      } else {
        if(j < A){
          ans[i][j] = 1;
        } else {
          ans[i][j] = 0;
        }
      }
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(j==W-1){
        cout << ans[i][j] << endl;
      } else {
        cout << ans[i][j];
      }
    }
  }
}
