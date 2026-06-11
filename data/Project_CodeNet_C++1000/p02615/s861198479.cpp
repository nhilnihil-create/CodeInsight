#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<long long> arr(N);
  long long ans = 0;
  for(int i = 0; i < N; ++i) {
    cin>>arr[i];
  }
  sort(arr.begin(), arr.end(), greater<int>());
  ans = arr[0];
  int idx = 1, cnt = 2;
  for(int i = 2; i < N; ++i) {
    ans += arr[idx];
    if(--cnt == 0) {
      ++idx; cnt = 2;
    }
  }
  cout<<ans<<endl;
  return 0;
}


