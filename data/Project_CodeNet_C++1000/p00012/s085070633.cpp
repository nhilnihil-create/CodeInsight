#include<iostream>
#include<complex>
#define EPS (1e-8)
#define EQ(a,b) (abs((a)-(b)) < EPS)
using namespace std;

typedef complex<double> P;
double cross(P x,P y){return imag(conj(x)*y);}
double area_tri(P a,P b,P c){return abs(cross(b-a,c-a)/2);}

int main(){
  P p[4];
  while(cin >> p[0].real() >> p[0].imag()){
    for(int i=1;i<4;i++)cin >> p[i].real() >> p[i].imag();
    double sum = 0;
    for(int i=0;i<3;i++)sum += area_tri(p[i],p[(i+1)%3],p[3]);
    if(EQ(sum,area_tri(p[0],p[1],p[2])))cout << "YES\n";
    else cout << "NO\n";
  }
}