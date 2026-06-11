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

const int INF = 1000000;

int main() {
  int N;
  vector<int> v;
  cin >> N;
  int m = INF;
  rep(i, N) {
    int temp;
    cin >> temp;
    if(m >= temp) {
      m = temp;
      v.push_back(i);
    }
  }
  cout << v.size() << endl;
  return 0;
}