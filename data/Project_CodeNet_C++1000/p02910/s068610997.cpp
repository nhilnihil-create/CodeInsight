#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool flag = true;
  for(long long int i = 0; i < S.size(); i++){
    if((i + 1) % 2 == 0 && S[i] == 'R') flag = false;
    if((i + 1) % 2 == 1 && S[i] == 'L') flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
