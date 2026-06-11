#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int   N;
  cin >> N;	
  vector<long long int> L(N);
  for(long long int i = 0; i < N; i++) cin >> L[i];
  
  if(N < 3){
    cout << 0 << endl;
    return 0;
  }
  
  sort(L.begin(),L.end());
  long long int ans = 0;
  for(long long int i = 2; i < N; i++){
    for(long long int j = 1; j < i; j++){
      for(long long int k = 0; k < j; k++){
        if(L[i] != L[j] && L[j] != L[k] && L[k] != L[i] && L[j] + L[k] > L[i]) ans++;
      }
    }
  }
  cout << ans << endl;
}
