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
  long long N;
  cin >> N;
  long long sum = 0;
  long long cnt = 0;
  rep(i, N+1) {
    if(i == 0) continue;
    if(i % 3 == 0 || i % 5 == 0) continue;
    sum += i;
  }
  cout << sum << endl;
  return 0;
}