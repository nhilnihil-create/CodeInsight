#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int last = 0,ans = 0;
  bool boo = true;
  for(int i=0; i<S.size()-1; i++){
    if(S[i] != S[i+1]){
      boo = false;
    }
  }
  if(boo == true){
    cout << 0 << endl;
    return 0;
  }
  for(int i=0; i<S.size(); i++){
    if(S[i] == 'R'){
      last++;
    }
  }
  for(int i=0; i<last; i++){
    if(S[i] == 'W'){
      ans++;
    }
  }

  cout << ans << endl;
}
