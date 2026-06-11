#include<bits/stdc++.h>
using namespace std;
int main(){
  long long L,R; cin >> L >> R;
  long long ans = 9999999999;
  for(long long i = L; i <= R - 1; i++){
    for(long long j = i + 1; j <= R; j++){
      if( ((i % 2019) * (j % 2019) % 2019) == 0){
        cout << 0 <<endl;
        return 0;
      }
      else if(((i % 2019) * (j % 2019) % 2019) < ans){
        ans = ((i % 2019) * (j % 2019) % 2019);
      }
    }
  }
  cout << ans << endl;
}