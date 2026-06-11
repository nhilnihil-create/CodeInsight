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
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }

  int x = 0;
  for (int i = 0; i < N-1; i++) {
    if(vec.at(i) >= vec.at(i+1)){
      x++;
    } else if(vec.at(i) < vec.at(i+1) || i == N-2) {
      x = 0;
    }
    ans = max(x, ans);
  }

  cout << ans << endl;

  return 0;
}