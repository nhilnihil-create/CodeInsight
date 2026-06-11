#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;
  
  int ans = T.size();
  
  for(int i = 0; i < S.size() - T.size() + 1; i++){
    int count = 0;
    for(int j = 0; j < T.size(); j++){
      if(S[i+j] != T[j])
        count++;
    }
    if(count < ans)
      ans = count;
  }
  
  cout << ans << endl;
}
