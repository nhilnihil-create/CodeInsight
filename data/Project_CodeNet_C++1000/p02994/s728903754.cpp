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
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int N, L;
  cin >> N >> L;
  int chk = 1e9;

  int sum = 0, ans = 0;
  for (int i = 1; i <= N; i++) {
    sum += L+i-1;
  }


  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++) {
      if(i == j) continue;
      cnt += L+j-1;
    }
    if(chk >= abs(sum-cnt)){
      chk = abs(sum-cnt);
      ans = cnt;
    }
  }

  cout << ans << endl;

  return 0;
}