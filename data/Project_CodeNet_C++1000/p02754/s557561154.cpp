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

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  long long a = N / (A + B);
  long long b = N % (A + B);
  long long ans = A * a;
  long long plus;
  plus = min(A, b);
  ans += plus;
  cout << ans << endl;
  return 0;
}