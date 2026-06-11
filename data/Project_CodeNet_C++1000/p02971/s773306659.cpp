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
  int ans = 0;
  vector<int> vec(N);
  vector<int> arr(N);
  
  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
    arr.at(i) = a;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  int mx = vec.at(0);
  int subMax = 0;
  int cnt = 0;
  bool flag = false;
  for (int i = 0; i < N; i++){
    if(vec.at(i) == mx) cnt++;
    if(cnt > 1) {
      flag = true;
    }
    if(vec.at(i) < mx){
      subMax = max(subMax, vec.at(i));
    }
  }

  for (int i = 0; i < N; i++){
    if(arr.at(i) < mx || flag == true) cout << mx << endl;
    else cout << subMax << endl;
  }

  return 0;
}