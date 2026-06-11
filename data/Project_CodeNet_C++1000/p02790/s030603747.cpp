#include <bits/stdc++.h>
using namespace std;

void solve(long long a, long long b)
{
    long long larger, smaller;
    if (a >= b)
    {
        larger = a;
        smaller = b;
    }
    else
    {
        larger = b;
        smaller = a;
    }

    for (int i = 0; i < larger; i++)
    {
        cout << smaller;
    }
    cout << endl;
}

int main()
{
    long long a;
    scanf("%lld", &a);
    long long b;
    scanf("%lld", &b);
    solve(a, b);
    return 0;
}
