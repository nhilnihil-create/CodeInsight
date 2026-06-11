#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  vector<int64_t> sum(N+1);
  for(int i=0; i<N; i++){
    sum[i+1] = sum[i] + vec[i];
    sum[i+1] %= K;
  }
  
  for(int i=0; i<N+1; i++){
    sum[i] -= i;
    if(sum[i] < 0){
      sum[i] += K*(abs(sum[i])/K + 1);
    }
    sum[i] %= K;
  }
 
  
  int64_t ans = 0;
  
  map<int64_t,int64_t> mp;
  for(int i=0; i<N+1; i++){
    if(mp.count(sum[i])){
      mp[sum[i]]++;
    }
    else{
      mp[sum[i]] = 1;
    }
    if(i >= K){
      mp[sum[i-K]]--;
    }
    ans += mp[sum[i]] - 1;
  }
  cout << ans << endl;
}