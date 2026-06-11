#include<bits/stdc++.h>
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
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

int main() {
  int N;
  int a[200000], b[200000];
  cin >> N;
  rep(i, N) {
    cin >> a[i] >> b[i];
  }
  sort(a, a + N);
  sort(b, b + N);
  if(N % 2 != 0) {
    cout << b[N / 2] - a[N / 2] + 1 << endl;
  } else {
    int bef = a[N / 2] + a[N / 2 - 1];
    int aft = b[N / 2] + b[N / 2 - 1];
    cout << aft - bef + 1 << endl;
  }
  return 0;
}