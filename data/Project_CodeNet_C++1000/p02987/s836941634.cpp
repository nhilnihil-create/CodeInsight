#include <iostream>

using namespace std;

int main()
{
    string S ;
    char a , b , c , d ;
    cin >> S ;
    a = S[0] ;
    b = S[1] ;
    c = S[2] ;
    d = S[3] ;
    if((a == b && c == d && a != c) || (a == c && b == d && a != b)||(a == d && b == c && a != b))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
