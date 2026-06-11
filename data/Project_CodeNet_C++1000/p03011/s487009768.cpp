#include <iostream>
#include <algorithm>
using namespace std;

int main( void )
{
    int p, q, r;
    cin >> p >> q >> r;
    cout << p + q + r - max( { p, q, r } ) << endl;

    return 0;
}
