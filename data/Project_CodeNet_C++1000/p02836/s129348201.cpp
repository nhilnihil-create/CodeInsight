#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main() {
  int n,cnt = 0,m;
  string s,t,u;
  cin >> s;
  n = s.size();
  m = n;
  n /= 2;
  for (int i = 0; i < n; i++){
    t += s[i];
  }
  if (m % 2 == 1){
   n++;
   for (int i = n; i < n*2-1; i++){
    u += s[i];
   }
  }
  else{
   for (int i = n; i < n*2; i++){
    u += s[i];
   }
  }
  reverse(u.begin(), u.end());
  for (int i = 0; i < n; i++){
    if (t[i] != u[i]){
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}