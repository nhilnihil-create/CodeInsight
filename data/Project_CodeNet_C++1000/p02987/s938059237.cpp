#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2]){
    cout << "No";
    return 0;
  }
  if(s[0] == s[2] && s[1] == s[3]){
    cout << "Yes";
    return 0;
  }
  if(s[0] == s[3] && s[2] == s[1]){
    cout << "Yes";
    return 0;
  }
  if(s[0] == s[1] && s[2] == s[3]){
    cout << "Yes";
    return 0;
  }
  cout << "No";
}