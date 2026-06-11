#include<iostream>
#include<complex>

using namespace std;

typedef complex<double> P;
#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b)) <EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

double cross(P a, P b) {
	  return (a.real() * b.imag() - a.imag() * b.real());
}
int is_intersected_ls(P a1, P a2, P b1, P b2) {
	  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
		           ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

int main(void){
	P A,B,C,P,O;

	while(cin>>A.real()>>A.imag()>>B.real()>>B.imag()>>C.real()>>C.imag()>>P.real()>>P.imag()){
		O.real()=(A.real()+B.real()+C.real())/3;//ツ三ツ角ツ形ツづ個陳心
		O.imag()=(A.imag()+B.imag()+C.imag())/3;
		if(is_intersected_ls(O,P,A,B)){
			cout<<"NO"<<endl;
			continue;
		}
		if(is_intersected_ls(O,P,A,C)){
			cout<<"NO"<<endl;
			continue;
		}
		if(is_intersected_ls(O,P,C,B)){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
}