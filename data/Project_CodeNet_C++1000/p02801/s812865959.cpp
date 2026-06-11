#include <iostream>
using namespace std;

int main ()
{
    char C;
    cin >> C;
    if (C>='a' && C<='z')
    {
        C=C+1;
        cout << C << endl;
    }
    return 0;
}
