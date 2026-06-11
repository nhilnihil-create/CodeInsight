#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
    int a, b;
    int d, r;
    double f;

    scanf("%d", &a);
    scanf("%d", &b);

    d = a / b;
    r = a % b;
    f = (double)a / b;

    printf("%d %d %.5f\n", d, r, f);

    return 0;
}
