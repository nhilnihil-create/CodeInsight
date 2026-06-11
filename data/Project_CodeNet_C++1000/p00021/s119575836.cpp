#include <iostream>
#include <complex>

using namespace std;
typedef complex<double> P;

double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

int main(){
  int n;
  cin >> n;
  while(n--){
    P p[4];
    for(int i=0; i<4; i++)
      cin >> p[i].real() >> p[i].imag();
    if(cross(p[1]-p[0],p[3]-p[2])==0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}