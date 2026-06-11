#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N,sum=0,ans=2020202021;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    sum += vec[i];
  }
  int sumsum = 0;
  for(int i=0; i<=N; i++){
    sumsum += vec[i];
    ans = min(ans,abs(sum-sumsum*2));
  }
  cout << ans << endl;
}
