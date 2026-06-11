#include<bits/stdc++.h>

using namespace std;

using ll = long long;



int main(){
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for(int i=0; i<N; i++) cin >> L[i];
  
  int ans = 1;
  int D = 0;
  while(ans<=N){
    D += L[ans-1];
    if(D>X) break;
    
    ans++;
  
  }
  
  cout << ans << endl;
  
  return 0;
}