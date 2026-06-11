#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    char a, b, c;
    cin >> a >> b >> c;
    if((a=='7') || (b=='7') || (c=='7'))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
