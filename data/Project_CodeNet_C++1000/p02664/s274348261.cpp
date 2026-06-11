#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  string s;
  cin >> s;
  int len = s.length();
  rep(i, len){
    if(s.at(i) == '?')
      s.at(i) = 'D';
  }
  cout << s << endl;
}