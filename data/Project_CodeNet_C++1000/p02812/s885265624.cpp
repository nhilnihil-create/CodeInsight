#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int cnt = 0;
  rep(i, n){
    if(s.at(i) == 'C' && s.at(i - 1) == 'B' && s.at(i - 2) == 'A'){
      cnt++;
    }
  }
  cout << cnt << endl;
}
