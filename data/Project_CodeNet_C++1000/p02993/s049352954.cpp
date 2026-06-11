#include <iostream>

using namespace std;

int main()
{
    string S ;
    char a , b , c , s ;
     cin >> S ;
    a = S[0] ;
    b = S[1] ;
    c = S[2] ;
    s = S[3] ;

    if (a == b || b == c || c == s )
    {
            cout << "Bad"  << endl;

    }
    else
    {
            cout << "Good" << endl;

    }
    return 0;
}
