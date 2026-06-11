#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[6];
  int cnt = 0;
  cin >> S;
  if(S[2] == S[3]) cnt++;
  if(S[4] == S[5]) cnt++;
  if(cnt == 2) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}