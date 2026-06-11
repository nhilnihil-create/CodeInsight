#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    u_int a, b;
    cin >> a >> b;
    
    printf("%d %d %f\n", a / b, a % b, (double)a / (double)b);

    return 0;
}