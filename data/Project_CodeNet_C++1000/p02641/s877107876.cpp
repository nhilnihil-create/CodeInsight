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

int main(){
  int X, N, i=0;
  cin >> X >> N;
  vector<int> p(N);
  rep(i,0,N) {
    cin >> p[i];
  }
  while(true) {
    int A=X-i, B=X+i;
    bool a=true, b=true;
    rep(i,0,N) {
      if(A==p[i]){
        a=false;
      }
    }
    if(a){
      cout << A << endl;
      return 0;
    }
    rep(i,0,N) {
      if(B==p[i]){
        b=false;
      }
    }
    if(b){
      cout << B << endl;
      return 0;
    }
    i++;
  }
}