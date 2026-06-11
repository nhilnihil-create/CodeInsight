#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mxN = 2e5;
int n, k, a[mxN];

int check(int x)
{
    int amt = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     amt = a[i] / x;
    //     if (a[i] % x) amt++;
    // }

    for (int i = 0; i < n; i++) amt += (a[i] - 1) / x;

    return amt > k;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int pos = 0, mx = 1e9;
    for (int i = mx; i >= 1; i /= 2)
    {
        while(check(pos + i)) pos += i;
    }

    cout << pos + 1 << "\n";
}