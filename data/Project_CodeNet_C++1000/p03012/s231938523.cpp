#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> W(N);
  
  for(int i=0; i<N; i++) cin >> W[i];
  
  vector<int> sum(N+1, 0);
  for(int i=0; i<N; i++) sum[i+1] = sum[i] + W[i];
  
  int ans = 100000000;
  for(int i=1; i<N; i++){
    ans = min(ans, abs((sum[N]-sum[i])-sum[i]));
  }
  
  
  cout << ans << endl;
  
  return 0;
}