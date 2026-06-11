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

  int A, B, C;
  cin >> A >> B >> C;

  if( ((A == B) && (A != C)) ||
      ((A == C) && (A != B)) ||
      ((B == C) && (A != B))){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

  return 0;
}