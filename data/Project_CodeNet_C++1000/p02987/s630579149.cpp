#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[4];
  cin >> S;
  int x[26] = {0};
  int cnt = 0;
  for(int i = 0; i < 4; i++){
    x[S[i] - 65]++;
  }
  for(int i = 0; i < 26; i++)
    if(x[i]) cnt++;
  if(cnt == 2) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
