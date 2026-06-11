#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  
  string S;
  cin >> a >> S;
  int ans =0;
  for(int i=1;i<S.size();i++){
    if(S[i]!=S[i-1]) ans++;
  }
  cout << ans +1 << endl;
  return 0; 
}