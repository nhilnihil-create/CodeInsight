#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  int k;
  cin >> k >> s;
  if(s.size()<=k) cout << s << "\n";
  else cout << s.substr(0,k) << "..." << "\n";
  return 0;
}