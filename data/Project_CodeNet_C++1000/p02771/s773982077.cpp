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
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  if(a[0] == a[1]) {
    if(a[2] == a[1]) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  } else {
    if(a[0] == a[2] || a[1] == a[2]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}