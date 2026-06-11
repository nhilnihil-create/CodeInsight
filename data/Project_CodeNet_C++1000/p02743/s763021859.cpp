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
typedef long long ll;
using namespace std;

int main(void) {
  long double a, b, c, d=0.000000000000001;
  cin >> a >> b >> c;
  if (sqrt(a)+sqrt(b)+d<sqrt(c)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}