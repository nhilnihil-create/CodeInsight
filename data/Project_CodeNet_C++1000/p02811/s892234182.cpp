#include <iostream>
using namespace std;
int main(){
  int x, y;
  cin >> x >> y;
  if(500 * x < y) cout << "No";
  else cout << "Yes";
  return 0;
}