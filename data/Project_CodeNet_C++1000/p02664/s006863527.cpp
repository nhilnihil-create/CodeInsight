#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  int cnt=0;
  cin >> S;
  rep(i, S.size()) if(S.at(i)=='?') S.at(i)='D';
  cout << S << endl;    
}