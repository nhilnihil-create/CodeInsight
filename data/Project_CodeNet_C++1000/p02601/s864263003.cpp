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
  int A, B, C;
  int K;
  cin >> A >> B >> C >> K;
  int count=0;
  while (A>=B) {
    B*=2;
    count++;
  }
  while (B>=C) {
    C*=2;
    count++;
  }
  if (count<=K) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}