#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  cin >> S;
  int cnt = 0;
  string tmp = "", privious = "";

  for(int i = 0; i < S.size(); i++) {
    tmp += S[i];
    if(tmp == privious) {
      continue;
    }
    else {
      privious = tmp;
      tmp = "";
      cnt++;
    }
  }

  cout << cnt << endl;
  
  return 0;
}
