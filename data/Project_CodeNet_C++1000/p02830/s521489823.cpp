#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  string s, t;
  cin >> n;
  cin >> s >> t;
  string ans = "";
  rep(i, n){
    ans.push_back(s[i]);
    ans.push_back(t[i]);
  }
  cout << ans << endl;
  
  return 0;
}