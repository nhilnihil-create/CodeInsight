#include <iostream>
using namespace std;

int main(){
  long long a,b,c,d;
  cin >> a >> b >> c >> d ;
  long long ac,ad,bc,bd;
  
  ac=a*c;
  ad=a*d;
  bc=b*c;
  bd=b*d;
  
  long long biggest;
  biggest = max(ac,max(ad,max(bc,bd)));
  
  cout << biggest;
}