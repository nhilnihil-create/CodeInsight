#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  int len = S.size();
  len = (len-1) /2;
  bool flg = true;
  rep(i, len){
   if(S.at(i) != S.at(i+len+1)){
    flg = false;
    break;
   }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


