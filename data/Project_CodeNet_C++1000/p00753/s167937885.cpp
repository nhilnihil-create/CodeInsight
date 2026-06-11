#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a, i1, i2, i3;
    double i4;
    while(1){
    cin >> a;
    i1 = a;
        i3 = 0;
        if(a==0){break;}
    while(1){
        i1++;
        if(i1 > 2*a){break;}
    
    i2 = 2;
    while(1){
    if(i1 % i2==0){break;}
    i2++;
        i4 = sqrt(i1);
    if(i4<i2){i3++; break;}
    }
    }
        if(a == 1){i3++;}
        cout << i3 << endl;
    }
    return 0;
}