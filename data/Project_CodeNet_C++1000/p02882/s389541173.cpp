#define _USE_MATH_DEFINES
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    if(x*2 >= a*a*b){
        printf("%Lf\n", atan((long double)(2*(a*a*b - x))/(long double)(a*a*a))/M_PI*180.0);
    }else{
        printf("%Lf\n", atan((long double)(a*b*b)/(long double)(2*x))/M_PI*180.0);
    }
	return 0;
}