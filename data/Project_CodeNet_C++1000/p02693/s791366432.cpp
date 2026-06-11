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
  int K;
  int A, B;
  cin >> K;
  cin >> A >> B;
  for(int i = A; i <= B; i++) {
    if(i % K == 0) {
      cout << "OK" <<endl;
      return 0;
    }
  }
  cout << "NG" << endl;
  return 0;
}