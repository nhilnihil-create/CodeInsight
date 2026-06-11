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
  cin >> N;
  int count = 0;
  int key = 1;
  rep(i, N) {
    int temp;
    cin >> temp;
    if(temp == key) {
      count++;
      key++;
    }
  }
  int ans;
  if(count == 0) ans = -1;
  else ans = N - count;
  cout << ans << endl;
  return 0;
}