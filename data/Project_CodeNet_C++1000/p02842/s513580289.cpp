#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  ans=0;
  for (int X=0; X<=N; X++) {
    if (floor(1.08*X)==N) {
      ans=X;
    }
  }
  if (ans==0) {
    cout << ":(" << endl;
  }
  else {
    cout << ans << endl;
  }
}