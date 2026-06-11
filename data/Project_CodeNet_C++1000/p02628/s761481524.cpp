#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int x, y, c = 0;
    cin >> x >> y;
    int a[x];
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    sort(a, a + x);
    for (int i = 0; i < y; i++)
    {
        c = c + a[i];
    }
    cout << c;
    return 0;
}