#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a, ans;
  a = s.size();
  ans = 0;
  if(a % 2 == 0){
    for(int i = 0; i< (a / 2); i++){
      if(s.at(i) != s.at(a - 1 - i)){
        ans++;
      }
         }
         cout << ans;
         }
  if(a % 2 == 1){
    for(int i = 0; i< ((a-1) / 2); i++){
      if(s.at(i) != s.at(a - 1 - i)){
        ans++;
      }
         }
         cout << ans;
         }
  return 0;
}