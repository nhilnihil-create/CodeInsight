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

  int X, Y;
  cin >> X >> Y;

  int get_price_code = X < 4 ? (4 - X) * 100000 : 0;
  int get_price_implement = Y < 4 ? (4 - Y) * 100000 : 0;
  int won_both = (X == 1 && Y == 1 ? 400000 : 0);

  cout << get_price_code + get_price_implement + won_both << endl;

  return 0;
}
