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

string S;

int main() {
  cin >> S;
  char key = S[0];
  rep(i, 3) {
    if(S[i+1] == key) {
      cout << "Bad" << endl;
      return 0;
    }
    key = S[i+1];
  }
  cout << "Good" << endl;
  return 0;
}