#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    int a[20001] = {0};
    a[0] = 1;
    for (int i = 3; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 3];
        a[i] %= mod;
    }
    cout << a[n];
}