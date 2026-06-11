#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;

void koch_curve(int depth, const complex<double> &left, const complex<double> &right) {
	if(depth==0) {
		printf("%.8f %.8f\n",left.real(),left.imag());
		return;
	} else {
		complex<double> v1,v2,v3,rot={cos(M_PI/3),sin(M_PI/3)};
		v1=(2.0*left+right)/3.0;
		v3=(left+2.0*right)/3.0;
		v2=v1+(v3-v1)*rot;
		koch_curve(depth-1,left,v1);
		koch_curve(depth-1,v1,v2);
		koch_curve(depth-1,v2,v3);
		koch_curve(depth-1,v3,right);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	complex<double> v1={0.0,0.0},v2={100.0,0.0};
	koch_curve(n,v1,v2);
	printf("%.8f %.8f\n",v2.real(), v2.imag());
	return 0;
}