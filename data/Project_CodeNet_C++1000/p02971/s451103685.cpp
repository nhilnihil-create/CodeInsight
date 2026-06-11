#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int N;
int a[200000];
int b[200000];

int main() {
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  rep(i, N) {
    b[i] = a[i];
  }
  sort(b, b + N);
  int m = b[N-1];
  int key;
  key = lower_bound(b, b+N, m)- b;
  int m2;
  if(key != N-1) m2 = m;
  else m2 = b[key-1];

  rep(i, N) {
    if(a[i] != m) cout << m << endl;
    else cout << m2 << endl;
  }



  return 0;
}