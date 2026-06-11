#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  if(P != 2 && P != 5){
  reverse(S.begin(),S.end());
  vector<int> ten(N+1,10%P);
  for(int i=1; i<N+1; i++){
    ten[i] = (ten[i-1]*10)%P;
  }
  int64_t dp[N+1];
  for(int i=0; i<N+1; i++){
    dp[i] = 0;
  }
  for(int i=0; i<N; i++){
    int x = S.at(i) - '0';
    if(i == 0){
      dp[i] = x%P;
    }
    else{
      dp[i] = (dp[i-1] + x*ten[i-1])%P;
    }
    //cout << dp[i] << endl;
  }
  
  map<int64_t,int64_t> mp;
  for(int i=0; i<N+1; i++){
    if(mp.count(dp[i])){
      mp[dp[i]]++;
    }
    else{
      mp[dp[i]] = 1;
    }
  }
  
  int64_t ans = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    ans += (itr->second)*(itr->second-1)/2;
  } 
  cout << ans << endl;
  }
  else{
    int64_t cnt = 0;
    for(int i=0; i<S.size(); i++){
      int x = S.at(i) - '0';
      if(x %P == 0){
        cnt += i+1;
      }
    }
    cout << cnt << endl;
  }
}

