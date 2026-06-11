#include<iostream>
#include<complex>
using namespace std;
#define dff 1e-10
int main(){
  int n;
  cin >>n;
  while(n--){
    double x;
    complex<double> a[4];
    for(int i=0; i<4; i++) cin >>a[i].real()>>a[i].imag();
    for(int i=0; i<2; i++) a[i*2]-=a[i*2+1];
    x = a[0].real()*a[2].imag()-a[0].imag()*a[2].real();
    if(-dff<x && x<dff) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
  }
  return 0;
}