#include<stdio.h>
using namespace std;
int a = 0,b = 0;
int d = 0,r = 0;
double f = 0.0f;
int main(){
    scanf("%d %d", &a, &b);
    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
    printf("%d %d %f\n",d,r,f);

}
