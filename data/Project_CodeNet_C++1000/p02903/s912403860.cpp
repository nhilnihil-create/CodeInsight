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
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  if (B!=0) {
    if (A!=0) {
      for (int i=0; i<B; i++) {
        for (int j=0; j<A; j++) {
          cout << "0";
        }
        for (int j=A; j<W; j++) {
          cout << "1";
        }
        cout << endl;
      }
      for (int i=B; i<H; i++) {
        for (int j=0; j<A; j++) {
          cout << "1";
        }
        for (int j=A; j<W; j++) {
          cout << "0";
        }
        cout << endl;
      }
    }
    else {
      for (int i=0; i<B; i++) {
        for (int i=0; i<W; i++) {
          cout << "1";
        }
        cout << endl;
      }
      for (int i=B; i<H; i++) {
        for (int i=0; i<W; i++) {
          cout << "0";
        }
        cout << endl;
      }
    }
  }
  else {
    if (A!=0) {
      for (int i=0; i<H; i++) {
        for (int j=0; j<A; j++) {
          cout << "1";
        }
        for (int j=A; j<W; j++) {
          cout << "0";
        }
        cout << endl;
      }
    }
    else {
      for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
          cout << "0";
        }
        cout << endl;
      }
    }
  }
}