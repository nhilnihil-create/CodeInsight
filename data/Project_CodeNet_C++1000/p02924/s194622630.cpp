#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  ll N;
  cin >> N;
  ll ans = 0;

  for (ll i = 1; i < N; i++) {
    ans += i;
  }

  cout << ans << endl;

  return 0;
}