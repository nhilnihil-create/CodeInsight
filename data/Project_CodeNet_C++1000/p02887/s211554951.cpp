#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  string S;
  cin >> S;

  int ans = 1;
  char s = S[0];
  for(int i = 1; i < S.size(); i++) {
    if(S[i] != s) {
      s = S[i];
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
