#include <iostream>

using namespace std;

int main()
{
    int x;

    for(int i = 1;i <= 5; ++i)
    {
        cin >> x;
        if(!x)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
