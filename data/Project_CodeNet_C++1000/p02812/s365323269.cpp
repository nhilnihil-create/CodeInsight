#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
//~ using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n;
  string s;
  int cnt=0;
  
  cin >> n >> s;
  rep(i, n-2){
    if(s.substr(i, 3) == "ABC") cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}
