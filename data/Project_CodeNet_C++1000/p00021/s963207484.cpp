#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for( int i=0; i<n; ++i ) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << ( ( ( y2 - y1 ) * ( x4 - x3 ) == ( y4 - y3 ) * ( x2 - x1 ) ) ? "YES" : "NO" ) << endl;
    }
}