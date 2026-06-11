#include <iostream>
using namespace std;
#define min(a,b) ((a)<(b) ? (a) : (b))
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << c-min(a-b,c) << endl;
  return 0;
}