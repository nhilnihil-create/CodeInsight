
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
  string t = "Yes";
  int c = 0;
  rep(i,s.size()){
    if(i % 2){
      if(s[i] == 'L' || s[i] == 'U' || s[i] == 'D') t = c++;
    }
    else{
      if(s[i] == 'R' || s[i] == 'U' || s[i] == 'D') t = c++;
    }
  }
      
  cout << (c == s.size() ? "Yes" : "No") << endl;
  return 0;
}