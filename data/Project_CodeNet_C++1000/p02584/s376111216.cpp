#include <iostream>
#include <cstdlib>
#include <cmath>

void sub(long long int *x,long int *k, unsigned long int *d) {
    long long int tmp = *x / *d;

    if(*x % *d == 0) {
        tmp--;
    }

    if(tmp + 1 <= *k) {
        *k -= (tmp + 1);

        *x -= *d * (tmp + 1);
    }
    else {
        *x -= *d * *k;

        *k = 0;
    }
}

void sum(long long int *x, long int *k, unsigned long int *d) {
    *x *= -1;
    long long int tmp = *x / *d;

    if(*x % *d == 0) {
        tmp--;
    }

    *x *= -1;
    
    if(tmp + 1 <= *k) {
        *k -= (tmp + 1);

        *x += *d * (tmp + 1);
    }
    else {
        *x += *d * *k;

        *k = 0;
    }
}

int main() {
    long long int X;
    long int K;
    unsigned long int D;

    std::cin >> X >> K >> D;

    if(X > 0) {
        sub(&X, &K, &D);

        if(K > 0){
            if(K % 2 == 1) {
                X += D;
            } 

        }
    }
    else {
        sum(&X, &K, &D);

        if(K > 0) {
            if(K % 2 == 1) {
                X -= D;
            }
        }
    }

    if(X < 0) {
        X *= -1;
    }

    std::cout << X << std::endl;

    return 0;
}
