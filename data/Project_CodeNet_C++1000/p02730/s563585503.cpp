
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;
  
  int sz = s.size();
  rep(i, sz){
    if(s[i] != s[sz - i - 1]){
      cout << "No" << endl;
      return 0;
    }
  }
  int sz1 = (sz - 1)/2;
  int sz2 = (sz + 3)/2;
  rep(i, sz1){
    if(s[i] != s[sz1 - i - 1]){
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; sz2 < sz; sz2++){
    if(s[sz/2+1+i] != s[sz - i - 1]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}