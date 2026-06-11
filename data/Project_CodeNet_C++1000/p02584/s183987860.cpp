#include <bits/stdc++.h>
using namespace std;

int main()
{
    //input
    long long x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    //the shortest distance from the origin
    long long shor = min(k, x / d);
    k -= shor;
    x -= shor * d;

    if (k % 2 == 0)
    {
        cout << x << endl;
    }
    else
    {
        cout << d - x << endl;
    }

    return 0;
}

// TLE
/***
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //input
    long long x, k, d;
    cin >> x >> k >> d;

    //get close to the origin
    for (long long i = 0; i < k; i++)
    {
        long long p = abs(x + d);
        long long m = abs(x - d);
        if (p < m)
            x += d;
        else
            x -= d;
    }

    //output the absolute value of x
    cout << abs(x) << endl;
    return 0;
}
***/