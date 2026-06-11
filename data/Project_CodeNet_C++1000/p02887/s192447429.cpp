#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

  int n;
  string s;
  cin >> n >> s;
  int cnt = 1;

  REP(i,n-1){
    if(s[i] != s[i+1]) cnt++;
  }

  cout << cnt << endl;
  return 0;

}