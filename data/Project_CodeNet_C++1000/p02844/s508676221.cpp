#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, ans = 0;
  string S;
  cin >> n  >> S;
  for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      for (int k=0;k<10;k++){
        int cnt=0,iflag=0,jflag=0;
        while (true){
          if (cnt >= n) break;
          if (iflag == 0 && S[cnt] == '0'+i){
            iflag = 1;
            cnt += 1;
            continue;
          }
          if (iflag == 1 && jflag == 0 && S[cnt] == '0'+j){
            jflag = 1;
            cnt += 1;
            continue;
          }
          if (jflag == 1 && S[cnt] == '0'+k){
            ans ++;
            break;
          }
          cnt ++;
        }
      }
    }
  }
  cout << ans << endl;
}