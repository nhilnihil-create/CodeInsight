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
int a[100000], b[100000];
pair<int, int> c[100000];

int main() {
  cin >> N >> M;
  rep(i, N) {
    cin >> c[i].second >> c[i].first;
    c[i].second = M - c[i].second;
  }

  sort(c,c+N);
  vector<int> v;
  rep(i, M) {
    v.push_back(i);
  }
  int ans = 0;
  for(int i = N-1; i >= 0; i--) {
    int temp = c[i].first;
    int key = c[i].second;
    int r = upper_bound(v.begin(), v.end(), key) - v.begin();
    if(r == 0) continue;
    v.erase(upper_bound(v.begin(), v.end(), key)-1);
    ans += temp;
  }
  cout << ans << endl;

  return 0;
}