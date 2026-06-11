#include<iostream>
#include<cstdio>
using namespace std;

int a,b;
int d,r;
double f;

int main(){
    scanf("%d %d", &a, &b);
    d = a / b;
    r = a % b;
    f = 1.0 * a / b;
    printf("%d %d %9.5lf\n", d, r, f);
    return 0;
}