#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  long long h;
  cin >> h;
  long long count = 0;
  while(h > 1){
    h /= 2;
    count ++;
  }
  long long now = 1;
  long long ans = 0;
  for(int i = 0; i < count + 1; i++){
    ans += now;
    now *= 2;
  }
  cout << ans << endl;

  return 0;
}