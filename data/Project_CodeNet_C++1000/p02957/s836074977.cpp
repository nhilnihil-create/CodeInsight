#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if ((max(a, b) - min(a, b)) % 2 == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << (max(a, b) - min(a, b)) / 2 + min(a, b) << endl;
    }
}
