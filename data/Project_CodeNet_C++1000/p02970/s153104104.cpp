#include<stdio.h>
#include<iostream>

using namespace std;

int N,D;
int main () {
    cin >> N >> D;
    int c = 2 * D + 1;
    cout << N / c + ( N % c > 0) << endl;
    return 0;
}
