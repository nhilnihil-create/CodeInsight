#include<iostream>
#include<complex>
#include<map>

#define fs first
#define sc second
using namespace std;

typedef complex<double> P;
typedef pair<P,P> L;

const double EPS = 1e-8;
double cross(P x,P y){return imag(conj(x)*y);}
bool para(L a,L b){return abs(cross(a.fs-a.sc,b.fs-b.sc))<EPS;}

int main(){
  int n;
  P p[4];
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++)cin >> p[j].real() >> p[j].imag();
    cout << (para(L(p[0],p[1]),L(p[2],p[3]))?"YES":"NO") << endl;
  }
}