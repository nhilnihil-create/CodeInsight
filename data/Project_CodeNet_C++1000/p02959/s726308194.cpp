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

long long N;
long long a[100001];
long long b[100000];

int main() {
  cin >> N;
  rep(i, N+1) {
    cin >> a[i];
  }
  rep(i, N) {
    cin >> b[i];
  }
  
  long long ans = 0;
  rep(i, N) {
    long long temp = min(a[i], b[i]);
    ans += temp;
    long long minus = b[i] - temp;
    if(minus > a[i+1]) {
      ans += a[i+1];
      a[i+1] = 0;
    } else {
      ans += minus;
      a[i+1] -= minus;
    }
  }
  cout << ans << endl;
  return 0;
}