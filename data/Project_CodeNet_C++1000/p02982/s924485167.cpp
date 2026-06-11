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

  int N, D, x;
  cin >> N >> D;
  int ans = 0;

  vector<vector<int>> vec(N, vector<int>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> x;
      vec.at(i).at(j) = x;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      double dst = 0;
      for (int k = 0; k < D; k++) {
        dst += abs(vec.at(i).at(k) - vec.at(j).at(k))*abs(vec.at(i).at(k) - vec.at(j).at(k));
      }
      double r;
      double f = modf(sqrt(dst), &r);
      if(f == 0) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}