#include <iostream>
using namespace std;

int main(void)
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int a[m] = {};
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }

    int suma = 0;
    for (int i = 0; i < m; ++i)
    {
        suma += a[i];
    }

    if (suma <= n)
    {
        cout << n - suma;
    }
    else
    {
        cout << -1;
    }

    return 0;
}