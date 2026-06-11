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

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }

  bool flag = false;
  for (int i = 0; i < N; i++) {
    if(vec.at(i)%2 == 0){
      if(((vec.at(i)%3 == 0) || (vec.at(i)%5 == 0))){
        flag = true;
      } else {
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }

  // if(flag == true){
    cout << "APPROVED" << endl;
  // } else {
  //   cout << "DENIED" << endl;
  // }

  return 0;
}