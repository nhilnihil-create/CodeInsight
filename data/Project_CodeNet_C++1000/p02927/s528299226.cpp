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

  int M, D;
  cin >> M >> D;

  int cnt = 0;

  for(int i = 1; i <= M; i++) {
    for (int j = 1; j <= D; j++) {
      int d1 = j / 10;
      int d10 = j % 10;
      if(d1 > 1 && d10 > 1 && i == d1 * d10) {
        // cout << i << ": " << d1 << " " << d10 << endl;
        cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
