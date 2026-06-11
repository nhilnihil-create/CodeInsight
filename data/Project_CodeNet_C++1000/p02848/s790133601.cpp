#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for(int i = 0; i < S.size();i++){
    char ans = S.at(i) + N;
    if(ans > 'Z'){
      ans = ans - 'Z' + 'A'-1;
    } 
    cout << ans;
  }
}