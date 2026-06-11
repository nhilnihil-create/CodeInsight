#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main() {
  long long n;
  int ans = 0;
  cin >> n;
  if(n == 1){
    cout << ans << endl;
    return 0;
  }
  int num = sqrt(n);
  for(int i = 2; i < num; i++){
    int e = 1;
    int cnt = 0;
    while((n % (long long)pow(i,e)) == 0){
      cnt++;
      n /= pow(i,e);
      e++;
    }
    while(n % i == 0) n /= i;
    ans += cnt;
    if(n == 1) {
      cout << ans << endl;
      return 0;
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
