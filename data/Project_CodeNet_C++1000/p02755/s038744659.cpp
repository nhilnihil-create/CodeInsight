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
  int A, B, ans=-1;
  cin >> A >> B;
  for (int i=0; i<1001; i++) {
    if ((2*i)/25==A && i/10==B) {
      ans=i;
      break;
    }
  }
  cout << ans << endl;
}