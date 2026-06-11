#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main(){
 string S, T;
  cin >> S >> T;
  int ans = 0;
  
  rep(i, S.size()){
    if(S.at(i) != T.at(i)) ans++;
  }
  cout << ans << endl;
}
