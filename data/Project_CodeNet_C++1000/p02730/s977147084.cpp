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

int main() {
  string s;
  cin >> s;
  int N = s.size();
  bool f = true;

  rep(i, N) {
    if(s[i] != s[N-1-i]) {
      f = false;
    }
  }

  rep(i, (N-1)/2) {
    if(s[i] != s[(N-1)/2 - 1 - i]) {
      f = false;
    }
  }

  rep(i, N-(N+3)/2+1) {
    if(s[(N+3)/2-1+i] != s[N-1-i]) {
      f = false;
    }
  }

  if(f) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl; 
  }

  return 0;
}