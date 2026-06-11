#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, y) for (ll i = x; i < y; i++)

int main()
{
    int n;
    cin >> n;
    int a[n];
    int max = -2000000;
    int min = 2000000;

    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    int difference = max - min;
    int sum[difference+1];
    int coordinate = 2000000000;

    rep(i, 0, difference+1)
    {
        sum[i] = 0;
        rep(j, 0, n)
        {
            sum[i] += (a[j] - (min + i) )*(a[j] - (min + i) );
        }

        if (sum[i] < coordinate)
            coordinate = sum[i];
    }

    cout << coordinate << endl;

    return 0;
}