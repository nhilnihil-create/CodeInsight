#include <iostream>
#include <algorithm>
using namespace std;

int main( void )
{
    int a;
    char s[ 11 ];
    cin >> a >> s;
    cout << ( a < 3200 ? "red" : s ) << endl;

    return 0;
}
