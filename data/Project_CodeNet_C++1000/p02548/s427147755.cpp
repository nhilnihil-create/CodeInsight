#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  
  int ans = 0;
  cin >> N;

  for(int i=1;i<N;++i){
    for(int j=1;j<N;++j){
      if(i*j < N){
        ans++;
      }else{
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
