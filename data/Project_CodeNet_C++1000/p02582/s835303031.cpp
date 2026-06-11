#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s=="RRR") cout << 3 << "\n";
  else if(s=="RRS"|| s=="SRR") cout << 2 << "\n";
  else if(s=="SSS") cout << 0 << "\n";
  else cout << 1 << "\n";
  return 0;
}