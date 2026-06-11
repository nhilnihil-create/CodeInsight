#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;

  vector<int> A(N+1);
  long long sum = 0;
  for(int i = 0;i < N+1;i++) {
    cin >> A[i];
    sum += A[i];
  }

  long long ans = -1;
  if(N == 0) {
    if(A[0] == 1) ans = 1;
    cout << ans << endl;
    return 0; 
  }

  if(A[0] != 0) {
    cout << ans << endl;
    return 0;
  }

  ans = 1;
  long long cur = 1;

  for(int i = 1;i < N+1;i++) {
    cur *= 2;
    if(cur < A[i]) {
      cout << -1 << endl;
      return 0;
    }

    ans += min(cur,sum);
    cur = min(cur,sum) - A[i];
    sum -= A[i];
  }


  cout << ans << endl;


  

}
