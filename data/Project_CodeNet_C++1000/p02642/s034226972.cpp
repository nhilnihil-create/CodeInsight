#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  int N;
  cin >> N;

  vector<int> A(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ok[1000001] = {0};
  int cnt[1000001] = {0};
  
  for(int i = 0; i < N; i++) {
    cnt[A[i]]++;
  }
  
  for(int i = 1; i <= 1000000; i++) {
    if(cnt[i] > 0) {
      if(cnt[i] > 1) {
        ok[i] = 1;
      }

      for(int j = i + i; j <= 1000000; j += i) {
        ok[j] = 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(ok[A[i]] == 0) ans++;
  }

  cout << ans;



  return 0;
}