#include <iostream>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a != 0 || b != 0)
    {
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                cout << ((i + j) % 2 == 0 ? '#' : '.');
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}