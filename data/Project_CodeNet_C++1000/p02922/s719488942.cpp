#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (b == 1) {cout << 0; return 0;}

    int i = 1;

    int curr = a;

    while (curr < b)
    {
        curr = curr + a - 1;
        i++;
    }

    cout << i << '\n';
    return 0;
}
