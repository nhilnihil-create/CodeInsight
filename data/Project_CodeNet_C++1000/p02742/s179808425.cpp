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

  long long H, W;
  cin >> H >> W;

  if(H == 1 || W == 1) cout << 1 << endl;
  else cout << (H * W + 1) / 2 << endl;

  return 0;
}
