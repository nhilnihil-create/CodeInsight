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

  int N, a;
  cin >> N;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a-1;
  }

  for (int i = 1; i < N; i++){
    ans = max(ans, vec.at(i));
    if(vec.at(i-1) > vec.at(i)){
      // cout << "a" << endl;
      // cout << "ans " << ans << endl;
      if(ans - vec.at(i) > 1){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}