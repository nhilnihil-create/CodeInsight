#include <iostream>
using namespace std;
template<class T,class C> T max(T a,C b){ return ((a)>(T)(b) ? (a) : (T)(b)); }
int main(){
  int p,q,r;
  cin >> p >> q >> r;
  cout << p+q+r-max(p,max(q,r)) << endl;
  return 0;
}