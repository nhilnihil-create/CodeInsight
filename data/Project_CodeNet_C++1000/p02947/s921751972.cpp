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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

int main() {
  long long N;
  cin >> N;
  map<string, long long> mp;
  long long ans = 0;
  rep(i, N) {
    string temp;
    cin >> temp;
    sort(temp.begin(), temp.end());
    if(!mp[temp]) {
      mp[temp] = 1;
    } else {
      ans += mp[temp];
      mp[temp] = mp[temp] + 1;
    }
  }
  cout << ans << endl;
  return 0;
}