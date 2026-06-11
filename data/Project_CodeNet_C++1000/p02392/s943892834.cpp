#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cin  >> a >> b >> c;

    if(0 <= a && a <= 100 && 0 <= b && b <= 100 && 0 <= c && c <= 100)
    {
        if(a < b && b < c)
            cout << "Yes" << endl;

        else
            cout << "No" << endl;
    }
    
    return 0;
}