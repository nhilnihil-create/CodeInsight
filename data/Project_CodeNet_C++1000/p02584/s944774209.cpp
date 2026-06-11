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
#define rep(i,s,e) for (int64_t i=s; i<e; i++)
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int64_t X, K, D, mod, T;
  cin >> X >> K >> D;
  if (X<=0) {
    X=-X;
  }
  mod=X%D;
  T=(X-mod)/D;
  if (T>=K) {
    cout << X-D*K << endl;
  }
  else {
    if (T%2==K%2) {
      cout << mod << endl;
    }
    else {
      cout << D-mod << endl;
    }
  }
}