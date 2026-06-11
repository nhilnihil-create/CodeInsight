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
  string s,s1,t,t1,u,u1;
  int n;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n/2; i++){
    t += s[i];
  }
  for (size_t i = n/2+1; i < n; i++){
    u += s[i];
  }
  t1 = t;
  u1 = u;
  s1 = s;
  reverse(t.begin(), t.end());
  reverse(u.begin(), u.end());
  reverse(s.begin(), s.end());
  if (s == s1 && t == t1 && u == u1){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
  
  return 0;
}

