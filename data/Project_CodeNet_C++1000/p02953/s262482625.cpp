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
  int N;
  int a[100000];
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  for(int i = N - 1; i >= 1; i--) {
    if(a[i-1] == a[i] + 1) a[i-1]--;
    else if(a[i-1] <= a[i]) continue;
    else {
      cout << "No" << endl;
      return 0;
    }
    // cout << a[i-1] << endl;
  }
  cout << "Yes" << endl;
  return 0;
}