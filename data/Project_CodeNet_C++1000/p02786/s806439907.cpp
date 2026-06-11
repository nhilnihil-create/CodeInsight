// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <cmath>
#include <map>
#include <set> 

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  ll H;
  cin >> H;
  ll sum = 0;
  ll cur_monsters = 1;

  while (H > 0)
  {
    H /= 2;
    sum += cur_monsters;
    cur_monsters *= 2;
  }

  cout << sum << endl;
  return 0;
}