#include<iostream>
#include<complex>
using namespace std;
typedef complex<double> P;
double det(P a,P b){
  return (conj(a)*b).imag();
}
double solve(P a,P b,P p){
  return (conj(p)*b).imag()/det(a,b);
} 
int main(){
  P a,b,c,p;
  while(cin>>a.real()>>a.imag()>>b.real()>>b.imag()>>
	c.real()>>c.imag()>>p.real()>>p.imag()){
    double s=solve(b-a,c-a,p-a),t=solve(c-a,b-a,p-a);
    cout<<(0<s&&s<1&&0<t&&t<1&&s+t<1?"YES":"NO")<<endl;
  }
  return 0;
}