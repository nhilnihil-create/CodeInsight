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
  int N, a;
  cin >> N;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }

  bool flag = false;
  int check = 1;
  for (int i = 0; i < N; i++) {
    if(vec.at(i) == check){
      flag = true;
      ans++;
      check++;
    }
  }

  if(flag == true){
    ans = N - ans;
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}