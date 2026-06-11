#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;
  vector<int> res(0);
  
  for (int i = 0; i < S.size() - T.size() + 1; i++){
    int ans = 0;
    
    for (int j = 0; j < T.size(); j++){
      if (S[i + j] != T[j]){
        ans++;
      }
    }
    
    res.push_back(ans);
  }
  
  sort(res.begin(), res.end());
  cout << res[0] << endl;
}