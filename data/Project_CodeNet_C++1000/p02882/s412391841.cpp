// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  
  double volume = a*a*b;
  double theta;
  if (volume / 2.0 < x) {
    theta = atan(2.0 * (volume - x) / (a*a*a)) * 180.0 / M_PI;
  }
  else {
    theta = (M_PI * 0.5 - atan(2.0 * x / (b*b*a))) * 180.0/ M_PI;
  }
  cout << fixed << setprecision(16) << theta << endl;
  return 0;
}

