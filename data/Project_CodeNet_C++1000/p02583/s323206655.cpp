#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  if(N<3){
    cout << 0 << endl;
    return 0;
  }
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  int ans = 0;
  sort(vec.begin(),vec.end());
  for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1; j++){
      for(int k=j+1; k<N; k++){
        if(vec[i]!=vec[j] && vec[i]!=vec[k] && vec[j]!=vec[k] && vec[i]+vec[j] > vec[k]){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
  
