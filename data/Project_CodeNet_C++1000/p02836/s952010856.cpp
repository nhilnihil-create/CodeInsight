#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  if(n % 2 != 0){
    rep(i,(n-1)/2){
      if(s.at(i) != s.at(n-1-i)) cnt++;
    }
  }else{
    rep(i,n/2){
      if(s.at(i) != s.at(n-1-i)) cnt++;
    }
  }
  cout << cnt << endl;
  }
