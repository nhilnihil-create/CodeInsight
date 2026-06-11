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

  int cnt = 0;
  while (true) {
    cnt++;
    if((cnt * X) % 360 == 0) break;
  }

  cout << cnt << endl;

  return 0;
}
