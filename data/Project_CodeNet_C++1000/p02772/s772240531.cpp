#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        if (!(x % 2))
        {
            if (x % 3 && x % 5)
            {
                cout << "DENIED\n";
                return 0;
            }
        }
    }

    cout << "APPROVED\n";
}