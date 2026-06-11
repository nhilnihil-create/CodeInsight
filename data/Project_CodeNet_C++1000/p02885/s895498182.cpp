#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(2*b >= a)
    {
        cout << 0;
        return 0;
    }
    else
        cout << a - 2*b;
    return 0;
}
