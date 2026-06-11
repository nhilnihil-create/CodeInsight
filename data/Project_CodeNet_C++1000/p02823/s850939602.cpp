#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
int64_t ans(int64_t A ,int64_t B, int64_t N){
  if((B - A)%2 == 0){
    return (B-A)/2;
  }
  else if(A == 1 || B == N){
    return 1 + ans(A,B-1,N);
  }
  else if(A-1 < N-B){
    return A - 1 + ans(1,B - (A - 1),N);
  }
  else{
    return N - B + ans(A + N - B ,N,N);
  }
}
int main() {
  int64_t N,A,B;
  cin >> N >> A >> B;
  cout << int64_t(ans(A , B , N)) << endl;
  return 0;
}