#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main(){
    double a,b;
    cin >> a >> b;

    cout << (int)a/(int)b <<" "<< (int)a%(int)b<<" ";
    printf("%.5f\n",a/b);
    return 0;
}
