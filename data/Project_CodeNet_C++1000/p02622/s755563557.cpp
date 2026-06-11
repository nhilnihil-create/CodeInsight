#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int   N;
  string S, T;
  cin >> S >> T;
  
  long long int ans = 0;
  for(long long int i = 0; i < S.size(); i++){
    if (S.at(i) != T.at(i)) ans++;
  }
  cout << ans << endl;
}
