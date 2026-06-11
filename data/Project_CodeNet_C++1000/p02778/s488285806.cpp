#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  string ans(n, 'x');
  cout << ans << endl;
  
  return 0;
}