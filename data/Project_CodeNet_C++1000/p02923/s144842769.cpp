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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

int main() {
  long long N;
  long long H[100000];
  cin >> N;
  rep(i, N) {
    cin >> H[i];
  }
  long long key = H[0];
  long long count = 0;
  long long a[100000];
  a[0] = 0;
  rep(i, N-1) {
    if(H[i+1] <= key) {
      count++;
      a[i+1] = count;
    } else {
      count = 0;
      a[i+1] = count;
    }
    key = H[i+1];
  }
  long long ans = 0;
  rep(i, N) {
    ans = max(ans, a[i]);
    // cout << a[i] << endl;
  }
  cout << ans << endl;
  return 0;
}