#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int a,b,d,r;
    double f,fa,fb;
    cin >> a >> b;

    fa=a;
    fb=b;
    
    d = a / b;
    r = a % b;
    f = fa / fb;
    
    printf("%d %d %.8lf\n", d, r, f);
    return 0;
}
    