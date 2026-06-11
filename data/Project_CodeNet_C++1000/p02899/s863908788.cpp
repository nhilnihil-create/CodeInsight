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
  P a[100000];
  cin >> N;
  rep(i, N) {
    int temp;
    cin >> temp;
    a[i].first = temp;
    a[i].second = i+1;
  }

  sort(a, a+N);

  rep(i, N) {
    cout << a[i].second;
    if(i != N-1) cout << " ";
    else cout << endl;
  }

  return 0;
}