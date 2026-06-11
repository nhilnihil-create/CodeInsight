#include<iostream>
#include<complex>

#define EPS 1e-10
using namespace std;

typedef complex<double> P;


double cross(P p1,P p2){
	return p1.real()*p2.imag()-p1.imag()*p2.real();
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		P p[2];
		for(int i=0;i<2;i++){
			P tp[2];
			for(int j=0;j<2;j++){
				cin>>tp[j].real()>>tp[j].imag();
			}
			p[i]=tp[1]-tp[0];
		}
		if(abs(cross(p[0],p[1]))<=EPS)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}