#include <bits/stdc++.h>
#define REP(a,b,c) for(int a=b; a<(int)c; a++)
#define REPD(a,b,c) for(int a=b; a>(int)c; a--)
#define rep(a,b) REP(a,0,b)
#define repd(a,b) REPD(a,b,0)
typedef long long int ll;
using namespace std;

void show(vector<vector<int> > board){
  rep(i,board.size()){
    rep(j,5){
      cout << board[i][j];
    }
    cout << endl;
  }
}


int main(){
  while(true){
    int H;
    cin >> H;
    if(H == 0) break;
    vector<vector<int> > board(H, vector<int>(5, 0));
    rep(i,H)rep(j,5) cin >> board[i][j];
    int ans = 0;
    while(true){
      bool isFin = true;
      //      show(board);
      //cout << endl;
      rep(i,H){
        int num = board[i][0], cnt = 1;
        int j;
        for(j=1;j<5; j++){
          if(num == board[i][j]){
            cnt++;
          }else{
            if(cnt >= 3) break;
            num = board[i][j];
            cnt = 1;
          }
        }
        if(cnt >= 3 && num != 0){
          ans += cnt * num;
          int first_idx = j-cnt;
          for(int k=0; k < cnt; k++){
            board[i][first_idx+k] = 0;
          }
          isFin = false;
        }
      }
      for(int i=H-1; i>=0; i--){
        rep(j,5){
          if(board[i][j] == 0){
            for(int k=i-1; k>=0; k--){
              if(board[k][j] != 0){
                board[i][j] = board[k][j];
                board[k][j] = 0;
                break;
              }
            }
          }
        }
      }
      if(isFin) break;
    }
    cout << ans << endl;
  }
  return 0;
}