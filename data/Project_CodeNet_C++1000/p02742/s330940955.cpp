#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    if (h == 1 || w == 1) {cout << 1 << '\n'; return 0;}

    int h1,h2,w1,w2;
    if (h%2==0)
    {
        h1 = h/2;
        h2 = h/2;
    }
    else
    {
        h1 = h/2+1;
        h2 = h1-1;
    }

    if (w%2==0)
    {
        w1 = w/2;
        w2 = w/2;
    }
    else
    {
        w1 = w/2+1;
        w2 = w1-1;
    }

    cout << (long long)h1*w1 + (long long)h2*w2 << '\n';

    return 0;
}
