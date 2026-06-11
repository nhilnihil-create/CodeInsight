#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long x;
    cin >> x;

    long long r = x /100;
    long long amari = x % 100;

    if(amari <= 5*r){
        printf("1\n");
    }
    else{
        printf("0\n");
    }

    return 0;
}