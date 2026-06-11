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

int N, M;

int main() {
  cin >> N >> M;
  int a[100000] = {0};
  int b[100000] = {0};
  rep(i, M) {
    int temp;
    string res;
    cin >> temp >> res;
    temp--;
    if(res == "WA") {
      if(b[temp] == 0) {
        a[temp]++;
      }
    } else {
      if(b[temp] == 0) {
        b[temp] = 1;
      }
    }
  }
  int ans1 = 0, ans2 = 0;
  rep(i, N) {
    if(b[i] != 0) {
      ans1 += a[i];
    }
    ans2 += b[i];
  }
  cout << ans2 << " " << ans1 << endl;
  return 0;
}