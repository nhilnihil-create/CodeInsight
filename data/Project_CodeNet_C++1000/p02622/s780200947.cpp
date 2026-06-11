#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S, T;
  cin >> S >> T;

  int cnt = 0;
  for (int i = 0; i < S.size(); i++){
    if (S.at(i) != T.at(i)) cnt += 1; 
  }

  cout << cnt << endl;
}