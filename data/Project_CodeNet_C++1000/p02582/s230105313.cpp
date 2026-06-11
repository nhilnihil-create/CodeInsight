#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  string S;
  cin >> S;
  int cnt = 0;
  int cntmax = 0;
  rep(i, 3){
    if(S.at(i) == 'R')
      cnt++;
    else
      cnt = 0;
    cntmax = max(cnt, cntmax);
  }
  cout << cntmax << endl;
}
