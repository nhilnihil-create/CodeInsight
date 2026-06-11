#include <cstdio>
#include <cmath>

double theta = M_PI/3.0;

void koch(double *left, double *right, int m){
	if (m==0){
		std::printf("%f %f\n", left[0], left[1]);
	}
	else{
		double s[2], u[2], t[2];

		s[0] = (2*left[0] + right[0])/3.0;
		s[1] = (2*left[1] + right[1])/3.0;


		t[0] = (left[0] + 2*right[0])/3.0;
		t[1] = (left[1] + 2*right[1])/3.0;
		
		u[0] = std::cos(theta)*(t[0]-s[0]) - std::sin(theta)*(t[1]-s[1]) + s[0];
		u[1] = std::sin(theta)*(t[0]-s[0]) + std::cos(theta)*(t[1]-s[1]) + s[1];

		koch(left, s, m-1);
		koch(s, u, m-1);
		koch(u, t, m-1);
		koch(t, right, m-1);
	}
}

int main(){
	int n, i;
	double left[2], right[2];
	left[0]=0.;
	left[1]=0.;

	right[0]=100.0;
	right[1]=0.0;

	std::scanf("%d", &n);
	
	koch(left, right, n);
	std::printf("%f %f\n", right[0], right[1]);
	return 0;
}