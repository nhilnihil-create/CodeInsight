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
  int N, ans=1;
  string S;
  cin >> N >> S;
  if (N>1) {
    rep(i,0,N-1) {
      if (S[i]!=S[i+1]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}