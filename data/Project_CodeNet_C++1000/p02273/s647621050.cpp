#include<iostream>
#include<cmath>
#include<complex>
#include<cstdio>

void kock(int n,std::complex<double> p1,std::complex<double> p2){
	if(!n){
		printf("%.8f %.8f\n",p1.real(),p1.imag());
		return ;
	}
	std::complex<double> s,t,u;
	s.real((2*p1.real()+p2.real())/3);
	s.imag((2*p1.imag()+p2.imag())/3);
	t.real((p1.real()+2*p2.real())/3);
	t.imag((p1.imag()+2*p2.imag())/3);
	u.real(cos(M_PI/3)*(t.real()-s.real())-sin(M_PI/3)*(t.imag()-s.imag())+s.real());
	u.imag(sin(M_PI/3)*(t.real()-s.real())+cos(M_PI/3)*(t.imag()-s.imag())+s.imag());
	kock(n-1,p1,s);
	kock(n-1,s,u);
	kock(n-1,u,t);
	kock(n-1,t,p2);

}

int main(void){
	int n;
	const std::complex<double> LEFT(0,0);
	const std::complex<double> RIGHT(100,0);
	std::cin>>n;
	kock(n,LEFT,RIGHT);
	printf("%.8f %.8f\n",RIGHT.real(),RIGHT.imag());
	return 0;
}

