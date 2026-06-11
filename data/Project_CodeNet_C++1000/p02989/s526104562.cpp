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

int main() {
  int N;
  int a[100000];
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  sort(a, a+N);
  int ans = a[(N+1) / 2] - a[(N-1) / 2];
  cout << ans << endl;
  return 0;
}