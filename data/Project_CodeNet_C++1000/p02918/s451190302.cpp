#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin >> N >> K >> S;
  
  // 端...内側向くのがbetter
  // 途中...向かい合うflipは-2, 背を向けあうflipは0 or other
  // 最適...一方向orどこかを基準に向かい合い（N-1人）
  // LRLR...L 左端とRL
  // LRLR...R 左端とRLと右端
  // RLRL...R RLと右端
  // RLRL...L RL
  int rl=0;
  for(int i=0; i<N-1; i++){
    if(S[i]=='R'&&S[i+1]=='L') rl++;
  }
  
  if(S[0]=='R'){
    if(S[N-1]=='R'){
      if(K>=rl){
        cout << N-1 << endl;
      }else{
        cout << N-2*(rl-K)-1 << endl;
      }
    }else{
      if(K>=rl){
        cout << N-1 << endl;
      }else{
        cout << N-2*(rl-K) << endl;
      }
    }
  }else{
    if(S[N-1]=='R'){
      if(K>rl){
        cout << N-1 << endl;
      }else if(K==rl){
        cout << N-2 << endl;
      }else{
        cout << N-2*(rl-K)-2 << endl;
      }
    }else{
      if(K>=rl){
        cout << N-1 << endl;
      }else{
        cout << N-2*(rl-K)-1 << endl;
      }
    }
  }
}
  