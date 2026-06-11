#include <iostream>
using namespace std;

int main (){
  int a,b,c,k,n=0;
  cin >> a >> b >> c >> k;
  while (!(a<b)){
    b*=2;
    n++;
  }
  while (!(b<c)){
    c*=2;
    n++;
  }
  if (k>=n) cout << "Yes";
  else cout << "No";
}