#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;

  bool flg = true;

  REP(i, s.size()){
    if(i%2 == 1){
      if( s[i] == 'R') flg = false;
    }
    if(i%2 == 0){
      if( s[i] == 'L') flg = false;
    }
  }

  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
}
