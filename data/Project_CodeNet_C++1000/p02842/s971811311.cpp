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

  int N;
  cin >> N;
  int X = ((N + 1) / 1.08);
  if((int)(X * 1.08) == N) cout << X << endl;
  else cout << ":(" << endl;

  return 0;
}
