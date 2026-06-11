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

  int X;
  cin >> X;
  for(int i = 0; i < X + 1; i++) {
    int rest = X - i * 100;
    if(0 <= rest && rest <= 5*i) {
      cout << 1 << endl;
      return 0;
    }
    if(rest < 0) break;
  }
  cout << 0 << endl;

  return 0;
}
