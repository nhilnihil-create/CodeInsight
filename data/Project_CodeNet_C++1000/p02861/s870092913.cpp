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
  double ans = 0;
  vector<double> X(N);
  vector<double> Y(N);
  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
    v.at(i) = i+1;
  }

  double sum;
  int num = 0;
  do {
    for(int n = 1; n < N; n++){

      int i = v.at(n)-1;
      int j = v.at(n-1)-1;

      sum += sqrt(pow(X.at(i) - X.at(j),2.0)+pow(Y.at(i) - Y.at(j),2.0));
      // cout << sum << endl;
    }
    num++;
  } while (next_permutation(v.begin(), v.end()));

  ans = sum/num;

  printf("%.6lf\n", ans);

  return 0;
}