#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int an, l;
    while( cin >> an >> l, an||l ) {
        vector<int> xs;
        
        int i=1;
        for(;;) {
            xs.push_back( an );
            auto const as = to_string( an );
            auto lhs = string( l - as.size(), '0' ) + as;
            auto rhs = lhs;

            sort( lhs.begin(), lhs.end(), greater<char>() );
            sort( rhs.begin(), rhs.end() );

            an = stoi( lhs ) - stoi( rhs );
            
            auto const it = find( xs.cbegin(), xs.cend(), an );
            if ( it != xs.cend() ) {
                auto const j = distance( xs.cbegin(), it );
                cout << j << " " << an << " " << ( i - j )<< endl;
                break;
            }

            ++i;
        }
    }
}