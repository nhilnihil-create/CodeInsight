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
  string hitachi = "";
  for(int i = 0; i < 5 ; i++) {
    hitachi += "hi";
    if(hitachi == S) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
