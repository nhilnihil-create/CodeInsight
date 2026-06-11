#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  bool flag = true;
  rep(i, n){
    if (i % 2 == 0 && s[i] == 'L' ||
        i % 2 == 1 && s[i] == 'R') flag = false;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}