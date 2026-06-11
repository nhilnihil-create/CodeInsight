#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    long long int a, b, k;
    cin >> a >> b;

    if ((a+b)%2 == 0) {
        k = (a+b)/2;
        cout << k << endl;;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
