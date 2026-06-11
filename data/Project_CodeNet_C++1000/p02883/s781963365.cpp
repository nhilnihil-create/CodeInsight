#include <bits/stdc++.h>
using namespace std;
#define int long long

int need(int N, vector<int> &A, vector<int> &F, int Z){
  int ans = 0, i;
  for(i = 0; i < N; i++){
    ans += max(0ll, A[i] - Z / F[i]);
  }
  return ans;
}

signed main(){
  int N, K, i;
  scanf("%lld%lld", &N, &K);
  vector<int> A(N), F(N);
  for(i = 0; i < N; i++){
    scanf("%lld", &A[i]);
  }
  for(i = 0; i < N; i++){
    scanf("%lld", &F[i]);
  }
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<int>());
  int l = -1, h, r = (int)(1e13);
  while(r - l > 1){
    h = (l + r) / 2;
    if(need(N, A, F, h) > K){
      l = h;
    }
    else{
      r = h;
    }
  }
  printf("%lld\n", r);
  return 0;
}