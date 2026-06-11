#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> P;
const double EPS = 1e-4;
int main(){
	int N;
	cin >> N;
	while(N--){
		P a,b,c,d;
		cin >> a.real() >> a.imag() >> b.real() >> b.imag() >> c.real() >> c.imag() >> d.real() >> d.imag();
		P one = b-a;
		P two = d-c;
		bool f = false;
		if( abs(one.real()) < EPS || abs(two.real()) < EPS ){
			f = abs(one.real()) < EPS && abs(two.real()) < EPS;
		}else{
			f = one.imag()/one.real() - two.imag()/two.real() == 0;
		}
		cout << (f?"YES":"NO") << endl;
	}
}