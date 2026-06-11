#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    unsigned long a, b;

    cin >> a >> b;
    cout << a/b << ' ' << a%b;
    printf(" %.6f\n", (double)a/(double)b);
}