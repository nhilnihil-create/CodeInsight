#include <bits/stdc++.h>
using namespace std;

int main(){
  string S ;
  cin >> S ;
  int a = S.size();
  bool ans = true;
  for(int i=0;i<a;i++){
    if(i%2!=0&&S[i]=='R') ans = false;
    if(i%2==0&&S[i]=='L') ans = false;
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
