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
  int64_t N, A, B, ans;
  cin >> N >> A >> B;
  if (A%2==B%2) {
    ans=(B-A)/2;
  }
  else {
    ans=min((A-1),(N-B))+1+(B-A-1)/2;
  }
  cout << ans << endl;
}