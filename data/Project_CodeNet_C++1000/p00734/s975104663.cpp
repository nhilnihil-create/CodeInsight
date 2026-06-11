#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector <int> VI;

int main( void )
{
    int n, m;
    while ( cin >> n >> m && n && m )
    {
        int mins = -1, ct, ch;
        VI T(n), H(m);
        for ( int i = 0; i < n; i++ ) cin >> T[i];
        for ( int i = 0; i < m; i++ ) cin >> H[i];

        int ts = accumulate( T.begin(), T.end(), 0 ), hs = accumulate( H.begin(), H.end(), 0 );
        for ( int i = 0; i < n; i++ ) for ( int j = 0; j < m; j++ )
        {
            if ( ts - T[i] + H[j] == hs - H[j] + T[i] )
            {
                if ( mins == -1 || mins > T[i] + H[j] )
                {
                    mins = T[i] + H[j];
                    ct = T[i];
                    ch = H[j];
                }
            }
        }

        if ( mins == -1 )
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ct << " " << ch << endl;
        }
    }

    return 0;
}