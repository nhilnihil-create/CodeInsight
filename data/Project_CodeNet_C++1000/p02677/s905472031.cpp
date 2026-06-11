#include <iostream>
#include <vector>
#include <math.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define PI 3.1415926535897932
using namespace std;

int main(){
	int A,B;
	int H,M;
	cin>>A>>B>>H>>M;
	long double AngleH = ((long double)H / 12.0 + ((long double)M/60)/12) * 2.0*PI;
	long double AngleM = ((long double)M / 60.0) * 2.0*PI;
	long double Angle = (long double)abs(AngleH-AngleM);

	
	long double distance = sqrt((long double)(A*A + B*B - 2*A*B*cos(Angle)));
	printf("%20.20Lf\n",distance);
}