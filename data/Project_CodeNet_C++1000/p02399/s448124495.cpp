#include <stdio.h>

using namespace std;
int main(void){
    // Your code here!
    int a,b,d,r;
    double a_d,b_d,f;
    scanf("%d %d",&a,&b);
    a_d=static_cast<double>(a);
    b_d=static_cast<double>(b);
    printf("%d %d %.8f",a/b,a%b,a_d/b_d);
    return 0;
}
