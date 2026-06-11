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

  long long N;
  cin >> N;
  vector<long long> A(N);
  long long S = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    S += A[i];
  }

  long long minx = S, sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    minx = min(minx, abs(sum - (S - sum)));
  }
  cout << minx << endl;

  return 0;
}
