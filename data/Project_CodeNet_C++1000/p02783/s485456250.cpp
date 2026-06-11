#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, a;
    cin >> h >> a;
    int t = 0;
    while (h > 0)
    {
        t++;
        h -= a;
    }

    cout << t << endl;
}