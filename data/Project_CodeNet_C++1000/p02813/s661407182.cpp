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

// 順列を生成する
// Pとマッチするカウントを保存する
// Qとマッチするカウントを保存する
// 答えを出す

int main(){

  int N;
  cin >> N;
  int ans = 0;
  vector<int> P(N);
  vector<int> Q(N);
  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    v.at(i) = i+1;
  }

  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> Q.at(i);
  }

  int cnt = 0, p = 0, q = 0;

  do {
    bool pt = true, qt = true;

    cnt++;
    // cout << cnt << endl;

    for (int i = 0; i < N; i++) {
      // cout << v.at(i) << " " << P.at(i) << endl;
      // cout << v.at(i) << " " << Q.at(i) << endl;

      if(v.at(i) != P.at(i)) pt = false;
      if(v.at(i) != Q.at(i)) qt = false;
    }

    // cout << "pt "<< pt << endl;
    // cout << "qt "<< qt << endl;

    if(pt == true) p = cnt;
    if(qt == true) q = cnt;
    // cout << p << endl;
    // cout << q << endl;

  } while (next_permutation(v.begin(), v.end()));

  cout << abs(p-q) << endl;

  return 0;
}