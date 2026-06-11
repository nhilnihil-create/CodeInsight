#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    long long time = 0;
    long long p = 100;
    while (p < x)
    {
        p += p / 100;
        time++;
    }
    cout << time;
}
