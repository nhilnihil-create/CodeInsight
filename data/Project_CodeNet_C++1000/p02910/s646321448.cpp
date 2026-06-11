#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  bool have;
  have = true;
  rep(i,s.size()){
    if(i % 2 == 0 && s[i] == 'L'){
      have = false;
    }
    if(i % 2 == 1 && s[i] == 'R'){
      have = false;
    }
  }
  if(have){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
  
  return 0;
}