#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  string s;
  cin >> n >> s;
  if(n % 2 == 0){
    string t = s.substr(n/2, n/2);
    s = s.substr(0, n/2);
    if(s == t){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}