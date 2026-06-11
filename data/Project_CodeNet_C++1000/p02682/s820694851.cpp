#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A,B,C,K;
  cin >> A >> B >> C >> K;
  int64_t ans=0;
  ans+=min(A,K);
  if(A+B>=K){
    cout << ans << endl;
    return 0;
  }
  K-=A+B;
  ans-=K;
  cout << ans << endl;
}