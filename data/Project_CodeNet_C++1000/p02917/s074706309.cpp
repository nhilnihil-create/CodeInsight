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

  int N, b;
  cin >> N;
  int ans = 0;
  vector<int> vecA(N);
  vector<int> vecB(N-1);

  for (int i = 0; i < N-1; i++){
    cin >> b;
    vecB.at(i) = b;
  }

  for (int i = 0; i < N-1; i++){
    if(i == 0){
      vecA.at(i) = vecB.at(i);
      vecA.at(i+1) = vecB.at(i);
      continue;
    }

    if(vecA.at(i) > vecB.at(i)) vecA.at(i) = vecB.at(i);
    vecA.at(i+1) = vecB.at(i);
  }

  ans = accumulate(vecA.begin(), vecA.end(), 0);

  cout << ans << endl;

  return 0;
}