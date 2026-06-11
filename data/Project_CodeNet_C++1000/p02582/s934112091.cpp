#include <iostream>
using namespace std;
int main(){
  string s;
  int res = 0;
  cin >> s;
  for(char x : s){
    if(x == 'R') ++res;
  }
  if(res == 2 && s[1] == 'S') res --;
  cout << res << endl;
  return 0;
}
