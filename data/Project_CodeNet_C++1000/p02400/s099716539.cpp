#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    double r;
    cin >> r;
    double area = r * r * 3.141592653589;
    double circle = 2 * r * 3.141592653589;
    printf("%f %f",area,circle);
    return 0;
}