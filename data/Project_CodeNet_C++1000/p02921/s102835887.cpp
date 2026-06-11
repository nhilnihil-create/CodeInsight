#include <iostream>
#include <algorithm>
using namespace std;

int main( void )
{
    char s[ 4 ];
    char t[ 4 ];
    cin >> s >> t;
    int ans = 0;
    for ( int i = 0; i < 3; i++ )
    {
        if ( s[ i ] == t[ i ] )
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
