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

  long long A, B, V, W, T;
  cin >> A >> V >> B >> W >> T;

  long long D = abs(A-B);
  long long D2 = (V-W)*T;

  cout << (D <= D2 ? "YES" : "NO") << endl;
  return 0;
}
