#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long double a, b, c;

    cin >> a >> b >> c;

    long double delta = c - a - b;

    long double sqrt_ab = (long double)2*sqrt(a*b);
    //long double sqrt_a = (long double)sqrt(a);
    //long double sqrt_b = (long double)sqrt(b);

    if(delta < 0){
        printf("No\n");
    }
    else{
        if(delta > sqrt_ab){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}