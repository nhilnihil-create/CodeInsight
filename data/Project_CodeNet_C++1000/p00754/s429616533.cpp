#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int size = 101;
string line;
stack <char> S;

bool dfs( int i ) {
    if ( i == line.size() ) return S.empty();
    if ( line[i] == '(' || line[i] == '[' ) {
        S.push( line[i] );
    } else if ( line[i] == ')' || line[i] == ']' ) {
        if ( S.empty() ) return false;
        if ( S.top() == '(' && line[i] == ']' ) return false;
        if ( S.top() == '[' && line[i] == ')' ) return false;
        S.pop();
    }
    return dfs( i+1 );
}

int main() {
    while ( getline( cin, line ) && line != "." ) {
        S = stack<char>();
        bool result = dfs( 0 );
        cout << ( result ? "yes" : "no" ) << endl;
    }
    return 0;
}