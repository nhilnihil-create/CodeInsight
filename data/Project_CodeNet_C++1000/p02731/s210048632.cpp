#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int L;
    cin >> L;
    double V = double(L*L*L)/27;
    printf("%.7lf", V);
    return 0;
}