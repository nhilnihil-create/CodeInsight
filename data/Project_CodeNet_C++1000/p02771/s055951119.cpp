#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a==b && b==c) cout << "No" << "\n";
  else if(a!=b&&b!=c&&a!=c) cout << "No" << "\n";
  else cout << "Yes" << "\n";
  return 0;
}