#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int m = n/2;
  int ans = 0;
  rep(i, m){
    if (s[i] != s[n-i-1]) ans++;
  }
  cout << ans << endl;
  
  return 0;
}