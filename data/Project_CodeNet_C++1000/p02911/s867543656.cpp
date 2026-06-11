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
  int N, K, Q;
  cin >> N >> K >> Q;

  int a[100000];
  rep(i, N) {
    a[i] = K - Q;
  }

  rep(i, Q) {
    int temp;
    cin >> temp;
    temp--;
    a[temp]++;
  }
  rep(i, N) {
    if(a[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}