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

  ll N, a, b;
  cin >> N;
  ll ans = 0;
  vector<ll> A(N+1);
  vector<ll> B(N);

  for (int i = 0; i < N+1; i++){
    cin >> a;
    A.at(i) = a;
  }

  for (int i = 0; i < N; i++){
    cin >> b;
    B.at(i) = b;
  }

  for (int i = 0; i < N; i++){
    int left = min(A.at(i), B.at(i));
    ans += left;
    A.at(i) -= left;
    B.at(i) -= left;

    int right = min(A.at(i+1), B.at(i));
    ans += right;
    A.at(i+1) -= right;
    B.at(i) -= right;
  }

  cout << ans << endl;

  return 0;
}