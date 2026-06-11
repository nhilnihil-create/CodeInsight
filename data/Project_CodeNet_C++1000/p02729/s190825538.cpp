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

int main(){

  int N, M;
  cin >> N >> M;
  int ans = 0;

  if(N >= 2){
    ans += (N*(N-1))/2;
  }
  if(M >= 2){
    ans += (M*(M-1))/2;
  }
  cout << ans << endl;

  return 0;
}