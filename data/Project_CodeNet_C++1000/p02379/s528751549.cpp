#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    printf("%.8f\n",sqrt(pow(c-a,2)+pow(d-b,2)));
    
    return 0;
}