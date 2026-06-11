//Parallelism
#include<bits/stdc++.h>
using namespace std;

const double EPS=1E-12;

int main(){
  int n;
  cin>>n;
  complex<double> a, b, c, d;
  while(n--){
    cin>>a.real()>>a.imag()>>b.real()>>b.imag()>>c.real()>>c.imag()>>d.real()>>d.imag();
    a=a-b;
    c=c-d;
    cout<<(fabs(a.real()*c.imag()-a.imag()*c.real())<=EPS?"YES":"NO")<<endl;
  }

  return 0;
}