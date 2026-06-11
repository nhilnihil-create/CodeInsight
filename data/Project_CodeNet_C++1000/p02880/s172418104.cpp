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

  int N;
  cin >> N;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if(N == i*j){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}