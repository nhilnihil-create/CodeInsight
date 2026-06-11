#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <stdlib.h>
#include <deque>
#include <cstdint>
using namespace std;

int main () {
  long long int a, b, m;
  cin >> a >> b >> m;
  long long int sum = 0;
  long long int a_cost[a];
  long long int b_cost[b];
  int min_a = 100000;
  int min_b = 100000;
  for (int i = 0; i < a; i++){
    int tmp;
    cin >> tmp;
    a_cost[i] = tmp;
    if (tmp < min_a){
      min_a = tmp;
    }
  }
  for(int i = 0; i < b; i++){
    int tmp;
    cin >> tmp;
    b_cost[i] = tmp;
    if (tmp < min_b){
      min_b = tmp;
    }
  }
  sum = min_a + min_b;
  for (int i = 0; i < m; i++){
    int x, y, c;
    cin >> x >> y >> c;
    if (a_cost[x-1] + b_cost[y-1] - c < sum){
      sum = a_cost[x-1] + b_cost[y-1] - c;
    }
  }
  cout << sum;
  return 0;
}