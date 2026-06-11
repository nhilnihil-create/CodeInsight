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
using P = pair<int, int>;

int gcd(int a, int b) {
  if(b == 0) return a;
  int d;
  a = a % b;
  swap(a, b);
  d = gcd(a, b);
  return d;
}

int main() {
  int K;
  cin >> K;
  int sum = 0;
  int l[201][201];
  for(int b = 1; b <= K; b++) {
      for(int c = 1; c <= K; c++) {
        l[b][c] = gcd(b, c);
      }
  }
  for(int a = 1; a <= K; a++) {
    int g;
    for(int b = 1; b <= K; b++) {
      for(int c = 1; c <= K; c++) {
        sum += l[a][l[b][c]];
      }
    }
  }
  cout << sum << endl;
  return 0;
}