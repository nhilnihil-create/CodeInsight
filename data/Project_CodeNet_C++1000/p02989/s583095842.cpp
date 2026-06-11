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

  int N, a;
  cin >> N;
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }
  sort(vec.rbegin(), vec.rend());
  
  int half = vec.size()/2 -1;
  cout << vec.at(half) - vec.at(half+1) << endl;

  return 0;
}