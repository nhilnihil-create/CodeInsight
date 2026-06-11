#include <iostream>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  ll B[N-1];
  for (int i = 0; i < N - 1; i++){
    cin >> B[i];
  }
  
  ll ans = B[N-2] + B[0];
  for (int i = N - 2; i >= 1; i--){
    ans += min(B[i], B[i-1]);
  }

  printf("%lld\n", ans);
}
