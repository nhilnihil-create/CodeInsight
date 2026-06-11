#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;

const double pi = 3.141592653589793;

int main() {
    double a, b, C, sinc, cosc;
    scanf("%lf%lf%lf", &a, &b, &C);
    sinc = sin(pi / (180 / C));
    cosc = cos(pi / (180 / C));

    printf("%f\n", a*b*sinc / 2);
    printf("%f\n", sqrt(a*a + b*b - 2 * a*b*cosc) + a + b);
    printf("%f\n", b*sinc);

    return 0;
}