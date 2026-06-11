#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,c,d;
    double e;
    cin >> a >> b;
    c = a/b;
    d =a%b;
    e= 1.0*a/b;
    //printf("%d " "%d,%.5lf\n",c,d,e);
    // insert code here...
   // cout << c <<" " << d << " " ;
    printf("%d",c);
    printf(" ");
    printf("%d",d);
    printf(" ");
    printf("%.8lf\n",e);
    return 0;
}