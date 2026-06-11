#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  rep(i,0,s.size()){
    if(s[i] == '?') cout << 'D';
    else cout << s[i];
  }
  cout << "" << endl;
}