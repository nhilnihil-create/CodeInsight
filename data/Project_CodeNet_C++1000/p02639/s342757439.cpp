#include <iostream>
using namespace std;

int main(void)
{
    int a[5], i;
    for (i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < 5; i++)
    {
        if (a[i] == 0)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}