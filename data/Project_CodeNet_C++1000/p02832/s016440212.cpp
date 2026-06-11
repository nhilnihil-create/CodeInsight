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

  int N, a;
  cin >> N;
  int cnt = 0, num = 1;
  for(int i = 0; i < N; i++) {
    cin >> a;
    a == num ? num++ : cnt++;
  }
  cout << (cnt == N ? -1 : cnt) << endl;
  return 0;
}
