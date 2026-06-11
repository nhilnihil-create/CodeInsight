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

int N, M, ans, pena;

int main(){

  cin >> N >> M;
  vector<int> AC(N+1);
  vector<int> WA(N+1);

  vector<pair<int, string>> p(M);
  for (int i = 0; i < M; i++) {
    cin >> p[i].first >> p[i].second;
  }

  for (int i = 0; i < M; i++) {
    int n = p[i].first;
    if(p[i].second == "WA"){
      if(AC.at(n) != 1) WA.at(n) += 1;
    }else if(p[i].second == "AC"){
      if(AC.at(n) != 1) AC.at(n) = 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    if(AC.at(i) != 1) WA.at(i) = 0;
  }

  for (int i = 1; i <= N; i++) {
    ans += AC.at(i);
    pena += WA.at(i);
  }

  cout << ans << " " << pena << endl;

  return 0;
}

