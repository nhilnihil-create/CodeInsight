#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    while( getline( cin, s ) ) {
        if ( s == "." )
            break;

        bool b = true;
        stack<char> t;
        t.push( '\0' );
        for( auto c : string( s.cbegin(), s.cbegin() + s.find_last_of( '.' ) ) ) {
            b = [&]() mutable -> bool {
                if ( c == '(' || c == '[' )
                    t.push( c );
                else if ( c == ')' )
                    if ( t.top() == '(' )
                        t.pop();
                    else
                        return false;
                else if ( c == ']' )
                    if ( t.top() == '[' )
                        t.pop();
                    else
                        return false;
                return true;
            }();
            if ( !b )
                break;

        }
        cout << ( b && t.size() == 1 ? "yes" : "no" ) << endl;
    }
}