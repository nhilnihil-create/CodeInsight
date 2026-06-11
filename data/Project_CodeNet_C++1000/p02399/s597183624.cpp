#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    
    int d = a / b;
    int r = a % b;
    double f = (double) a / b;
    printf("%d %d %.10f\n",d,r,f);
    //cout << d << " " << r << " " << f << endl;

}