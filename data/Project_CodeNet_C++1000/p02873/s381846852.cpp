#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  cin >> S;

  int n = S.size(), a[n+1];
  for (int i = 0; i < n+1; i++){
    a[i] = 0;
  }
  
  for (int i = 0; i < n; i++){
    if (S[i] == '<') a[i+1] = a[i] + 1;
  }

  for (int i = n - 1; i >= 0; i--){
    if (S[i] == '>') a[i] = max(a[i], a[i+1] + 1);
  }

  long long ans = 0;
  for (int i = 0; i < n+1; i++){
    ans += a[i];
  }
  
  printf("%lld\n", ans);
}
