#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  string S; cin >> S;
  bool ok = false;
  if(S.at(0) == S.at(1)){
    if(S.at(2) == S.at(3) && S.at(0) != S.at(2)){
      ok = true;
    }
  } else if(S.at(0) == S.at(2)){
    if(S.at(1) == S.at(3) && S.at(0) != S.at(1)){
      ok = true;
    }
  } else if(S.at(0) == S.at(3)){
    if(S.at(1) == S.at(2) && S.at(0) != S.at(1)){
      ok = true;
    }
  }
  if(ok){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}