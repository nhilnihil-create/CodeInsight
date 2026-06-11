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
  int64_t K, P=0;
  cin >> K;
  vector<int64_t> A(K);
  A[0]=7;
  if (K==1||K==7) {
    cout << 1 << endl;
  }
  else {
    rep(i,1,K) {
      A[i]=10*A[i-1]+7;
      A[i]%=K;
    }
    rep(i,0,K) {
      if (A[i]==0) {
        cout << i+1 << endl;
        break;
      }
      else {
        P++;
      }
    }
    if (P==K) {
      cout << -1 << endl;
    }
  }
}