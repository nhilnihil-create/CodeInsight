#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;
  rep(i, S.size()){
    int count = 0;
    rep(j, S.size()){
      if (i == j) continue;
      if (S.at(i) == S.at(j)) count += 1;
    }
    if (count != 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}