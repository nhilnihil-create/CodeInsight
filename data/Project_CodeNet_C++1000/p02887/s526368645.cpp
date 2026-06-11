#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  int ans = 0;
  char now = ' ';
  rep(i, n){
    if (now != s[i]){
      ans++;
      now = s[i];
    }
  }
  cout << ans << endl;
  
  return 0;
}