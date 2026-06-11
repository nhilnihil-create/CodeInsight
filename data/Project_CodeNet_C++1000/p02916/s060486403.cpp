#include <iostream>

using namespace std;

int A[21];
int B[21];
int C[21];

int main() {

  int n;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> A[i];
  }
  for(int i = 1;i <= n;i++){
    cin >> B[i];
  }
  for(int i = 1;i < n;i++){
    cin >> C[i];
  }
  int old = -1, now, ans = 0;
  for(int i = 1;i <= n;i++){
    now = A[i];
    ans += B[now];
    if(old == now - 1){
      ans += C[old];
    }
    old = now;
  }
  cout << ans;
  return 0;
}
