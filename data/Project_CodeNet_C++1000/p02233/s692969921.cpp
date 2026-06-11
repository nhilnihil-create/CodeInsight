#include<iostream>
using namespace std;

int fib(int n, int FIB[]){
    if (FIB[n]) return FIB[n];
    return FIB[n] = fib(n - 1, FIB) + fib(n - 2, FIB);
}

int main(){
    int n;
    cin >> n;
    int FIB[n+1] = {};
    FIB[0] = 1;
    if (n > 0) FIB[1] = 1;
    cout << fib(n, FIB) << endl;

    return 0;
}