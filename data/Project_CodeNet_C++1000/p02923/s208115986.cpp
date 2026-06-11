#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  
  if(N==1){
    cout << 0 << endl;
    return 0;
  }
  
  vector<ll> H(N);
  vector<ll> can_move(N-1);
  cin >> H[0];
  for(int i=1; i<N; i++){
    cin >> H[i];
    if(H[i-1]>=H[i]){
      can_move[i-1] = 1;
    }else{
      can_move[i-1] = 0;
    }
  }
  
  int cnt = 0;
  int i = 0;
  int ans = 0;
  while(true){
    
    if(can_move[i]==1){
      cnt += 1;
      ans = max(ans, cnt);
    }else{
      cnt = 0;
    }
    
    i += 1;
    if(i==N-1) break;
  }
  
  cout << ans << endl;

  return 0;
}