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
  int N, R;
  cin >> N;
  vector<int> X(N);
  for (int i=0; i<N; i++) {
    cin >> X[i];
  }
  sort(X.begin(),X.end());
  R=X[N-1]-X[0]+1;
  vector<int> P(R);
  for (int i=0; i<R; i++) {
    P[i]=0;
    for (int j=0; j<N; j++) {
      P[i]=P[i]+(X[j]-(X[0]+i))*(X[j]-(X[0]+i));
    }
  }
  sort(P.begin(),P.end());
  cout << P[0] << endl;
}