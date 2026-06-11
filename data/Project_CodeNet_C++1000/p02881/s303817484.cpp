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
  cin >> N;
  long long key;
  for(long long i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      key = i;
    }
  }
  long long ans = key + N / key - 2;
  cout << ans << endl;
  return 0;
}