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
  int N, M;
  int a[100];
  cin >> N >> M;
  rep(i, N) {
    cin >> a[i];
  }

  int sum = 0;
  rep(i, N) {
    sum += a[i];
  }
  int key = sum / (4 * M);
  if(sum % (4 * M) == 0) key--;
  int ans = 0;
  rep(i, N) {
    if(a[i] > key) ans++;
  }

  if(ans >= M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
