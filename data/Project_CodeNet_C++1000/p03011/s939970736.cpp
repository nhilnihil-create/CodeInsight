#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int p , q , r , m1 , m2 , m3 ;
    cin >> p >> q >> r ;
    m1 = p + q ;
    m2 = p + r ;
    m3 = r + q ;
    cout << min(min(m1,m2),m3) ;
    return 0;
}
