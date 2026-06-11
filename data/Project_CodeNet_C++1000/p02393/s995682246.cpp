#include <iostream>
using namespace std;
   
int main() {
  int a, b, c, tmp;
  cin >> a >> b >> c;
  int ary[3] = {a, b, c};
  if (ary[0] > ary[1]) {
    tmp = ary[0];
    ary[0] = ary[1];
    ary[1] = tmp;
  }
  if (ary[1] > ary[2]) {
    tmp = ary[1];
    ary[1] = ary[2];
    ary[2] = tmp;
  }
  if (ary[0] > ary[1]) {
    tmp = ary[0];
    ary[0] = ary[1];
    ary[1] = tmp;
  }
  cout << ary[0] << " " << ary[1] << " " << ary[2] << endl;
  return 0;
}