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
  int N, M, A=0, W=0;
  cin >> N >> M;
  vector<int> p(M);
  vector<string> S(M);
  rep(i,0,M) {
    cin >> p[i] >> S[i];
  }
  vector<int> a(N);
  vector<int> w(N);
  rep(i,0,N) {
    a[i]=0;
    w[i]=0;
  }
  rep(i,0,M) {
    if (S[i]=="AC") {
      a[p[i]-1]++;
    }
    else {
      if (a[p[i]-1]==0) {
        w[p[i]-1]++;
      }
    }
  }
  rep(i,0,N) {
    if (a[i]>0) {
      A++;
      W+=w[i];
    }
  }
  cout << A << " " << W << endl;
}
