#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  long long ans = 0;
  for(int k = 0; k < 1000; k++){
    int num = k;
    int cnt = n-1, three = 0;
    for(int div = 0; div < 3; div++){
      char c = num % 10 + '0';
      num /= 10;
      for(int i = cnt; i >= 0; i--){
        if(s.at(i) == c){
          cnt = i-1;
          three++;
          break;
        }
      }
    }
    if(three == 3) ans++;
  }
  
  cout << ans << endl;
}