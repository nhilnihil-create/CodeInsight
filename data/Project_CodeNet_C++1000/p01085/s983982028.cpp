#include <iostream>
using namespace std;

int main () {
  int m, nmin, nmax, tempa, tempb, sa=0;
  while(cin >>m>>nmin>>nmax) {
    int temp = 0;
    sa = 0;
    if(m == 0 && nmin == 0 && nmax == 0)break;
  cin>> tempa;
  for (int i=1;i<m;i++) {
    cin>> tempb;
    if(nmin <= i&& i<= nmax&&sa <= tempa - tempb) {
      sa = tempa - tempb;
      temp = i;
    }
    tempa = tempb;
  }
  cout << temp<< endl;
}
  return 0;
}
