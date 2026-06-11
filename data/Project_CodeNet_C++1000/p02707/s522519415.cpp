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
  int N;
  cin >> N;
  int a[200000] = {0};
  rep(i, N-1) {
    int temp;
    cin >> temp;
    temp--;
    a[temp]++;
  }
  rep(i, N) {
    cout << a[i] << endl;
  }
  return 0;
}