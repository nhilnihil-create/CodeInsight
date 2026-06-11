#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;

int main(){

  int N, a;
  cin >> N;
  int ans = 101;
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }

  int sumA = 0;
  for (int i = 0; i < N; i++) {
    sumA += vec.at(i);
    int sumB = 0;
    for (int j = i+1; j < N; j++) {
      sumB += vec.at(j);
    }
    ans = min(ans, abs(sumA - sumB));
  }

  cout << ans << endl;

  return 0;
}