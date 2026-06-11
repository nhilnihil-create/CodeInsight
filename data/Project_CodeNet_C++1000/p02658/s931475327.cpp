#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  long long ans = A.at(0);
  
  for(int i = 1; i < N; i++){
    if(ans == 0) break;
    else{
      long long div = 1000000000000000000LL / ans;
      if(div >= A.at(i)){
        ans *= A.at(i);
      }
      else{
        ans = -1;
        break;
      }
    }
  }
  cout << ans << endl;
}