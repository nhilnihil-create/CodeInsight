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
  int X, ans=0;
  cin >> X;
  if (X>=2000) {
    ans=1;
  }
  else {
    rep(h,0,20) {
      rep(i,0,20) {
        rep(j,0,20) {
          rep(k,0,20) {
            rep(l,0,20) {
              rep(m,0,20) {
                if (100*h+101*i+102*j+103*k+104*l+105*m==X) {
                  ans=1;
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}