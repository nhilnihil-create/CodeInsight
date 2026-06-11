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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

int main() {
  long long N, M;
  cin >> N >> M;
  long long a[10000];
  rep(i, M) {
    cin >> a[i];
  }
  long long sum = 0;
  rep(i, M) {
    sum += a[i];
  }
  long long ans = N - sum;
  if(ans < 0) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}