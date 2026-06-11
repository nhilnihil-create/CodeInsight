#include <iostream>
using namespace std;
int main(){
  int ans = 0;
  string s[2]; cin >> s[0] >> s[1];
  for(int i = 0; i < 3; i++){
    if(s[0][i] == s[1][i]) ans++;
  }
  cout << ans << endl;
}