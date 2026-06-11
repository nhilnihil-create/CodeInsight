#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long dfs(long long H) {
  if(H == 1) return H;
  H = 2 * dfs(H / 2) + 1;
  return H;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long H;
  cin >> H;
  cout << dfs(H) << endl;
  return 0;
}
