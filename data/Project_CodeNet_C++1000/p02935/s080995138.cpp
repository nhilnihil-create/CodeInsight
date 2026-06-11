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
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }
  sort(vec.begin(), vec.end());

  double avg = vec.at(0);
  for (int i = 1; i < N; i++){
    avg = (avg+vec.at(i))/2;
    // cout << avg << endl;
  }

  printf("%.5lf\n", avg);

  return 0;
}